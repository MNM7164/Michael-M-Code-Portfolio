#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

/*
* Game Configuration Constants:
*
* These are fixed sizes required by the assignment
* No dynamic memory is uses
* GRID_SIZE: dimensions of the board/map (10x10)
* MAX_TRAPS, MAX_TREASURES: count of maximum allowed
* FOG_RADIUS: tiles the player can see (Chebyshev distance)
*
*/

#define GRID_SIZE 10
#define MAX_TRAPS 10
#define MAX_TREASURES 5
#define FOG_RADIUS 2

/*
* Position structure
*
* Holds the grid coordinates (r,c)
*
* Chose r,c because they stand for row and column and
* sound like "Argh" and "Sea"
*
*/

typedef struct {
    int x;
    int y;
} Position;

/* 
* Game Structure
*
* Holds everything needed for gameplay:
* The Player, Traps, Treasure, Visibility, score, etc.
*/

typedef struct{
    Position player;
    Position traps[MAX_TRAPS];
    int num_traps;
    Position treasures[MAX_TREASURES];
    int num_treasures;
    int score;
    int game_over;

    // Fog of War (FOW) arrays:
    // visibility[][] -> tiles visible this turn
    // explored[][] -> tiles player has ever seen
    int visible[GRID_SIZE][GRID_SIZE];
    int explored[GRID_SIZE][GRID_SIZE];
} Game;


/* 
* Helper: Checks Grid Bounds
*
* Returns a 1 (T) if (r,c) is on grid, 0 (F) otherwise
*/

int in_bounds(int r, int c){
    return(r>=0 && r< GRID_SIZE && c >=0 && c < GRID_SIZE);
}

// Function Prototypes
void init_game(Game *g,int seed);
void update_visibility(Game *g);
int is_trap_at(const Game *g,int r, int c);
int treasure_index_at(const Game *g, int r, int c);
void print_board(const Game *g);
void collect_treasure(Game *g,int index);
void move(Game *g, char cmd);

// Main Game Loop
int main(void){
    Game game;
    int seed;
    char buf[100];

    printf("Welcome Matey to the yee ole treasure hunt\n");
    printf("Enter a seed (Or press enter to use a random seed): ");

    // Read an entire line to detect empty input
    fgets(buf, sizeof(buf), stdin);
    
    if(buf[0] == '\n'){
        // Empty seed -> use time-based seed
        seed = (&game,(int)time(NULL)); // random setups
        printf("Using random seed: %d\n",seed);
    }else{
        // Convert user input into integer
        seed = atoi(buf);
        printf("Using custom seed: %d\n",seed);
    }

    // Start Game
    init_game(&game, seed);

    printf("Argg yee controls be WASD, Q=quit\n");
    char cmd;
    while(!game.game_over){
        print_board(&game);
        printf("Score: %d, Dabloons remaining: %d\n",game.score,game.num_treasures);
        printf("Move (W/A/S/D, Q=quit): ");

        // Safe input handling: ignores invalid reads
        if(scanf(" %c",&cmd) != 1){
            continue;
        }

        cmd = toupper(cmd);
        if(cmd == 'Q'){
            printf("Yarr so long land lubber! Be seein you real soon.");
            break;
        }
        move(&game,cmd);
    }

    // Final Summary
    printf("Game Over.\n");
    printf("Final Score: %d\n",game.score);
    printf("Treasure Collected: %d of %d\n",game.score,4);
    return 0;
}

/* 
* Initializes the game
*
* Places traps and treasures randomly without overlap
* Also sets initial FOW visibility
*/

void init_game(Game *g,int seed){
    srand(seed);

    // Zero all data
    memset(g,0,sizeof(Game));

    g ->player.x=0;
    g ->player.y=0;

    g ->num_traps=7;
    g ->num_treasures=4;


    /*
    * Random trap placement
    *
    * Ensures traps do not:
    *  Overlap with the player
    *  Overlap with each other
    *  Overlap with treasures (checked after treasures are placed)
    */

    for(int i = 0;i<g->num_traps;i++){
        while(1){
            int r = rand() % GRID_SIZE;
            int c = rand() % GRID_SIZE;

            if(r==0 && c==0){
                // Avoids the Player's starting position
                continue;
            }
            int conflict = 0;
            for(int j=0;j<i;j++){
                if(g->traps[j].x==r&&g->traps[j].y==c){
                    conflict = 1;
                }
            }
            for(int k=0;k<g->num_treasures;k++){
                if(g->traps[k].x==r&&g->traps[k].y==c){
                    conflict = 1;
                }
            }
            if(!conflict){
                g->traps[i].x=r;
                g->traps[i].y=c;
                break;
            }
        }
    }

    /*
    * Random Treasure Placement
    *
    * Same Rules as the traps
    */
    for(int i=0;i<g->num_treasures;i++){
        while(1){
            int r = rand() % GRID_SIZE;
            int c = rand() % GRID_SIZE;

            if(r==0 && c==0){
                continue;
            }

            int conflict = 0;

            // Checks traps
            for(int j=0;j<i;j++){
                if(g->traps[j].x==r&&g->traps[j].y==c){
                    conflict = 1;
                }
            }

            // Checks the placement of earlier treasures
            for(int k=0;k<g->num_treasures;k++){
                if(g->traps[k].x==r&&g->traps[k].y==c){
                    conflict = 1;
                }
            }
            if(!conflict){
                g->treasures[i].x=r;
                g->treasures[i].y=c;
                break;
            }            
        }
    }
    update_visibility(g);
}


/*
* Updates FOW
*
* Marks tiles within FOG_RADIUS as visible this turn,
* and permenently marks them as explored.
*/

void update_visibility(Game *g){
    // Clear old visibility
    for(int r =0;r<GRID_SIZE;r++){
        for(int c=0;c<GRID_SIZE;c++){
            g->visible[r][c]=0;
        }
    }

    int pr = g->player.x;
    int pc = g->player.y;

    // Chebyshev distance
    for(int r =0;r<GRID_SIZE;r++){
        for(int c=0;c<GRID_SIZE;c++){
            int dr =abs(r-pr);
            int dc =abs(c-pc);

            if(dr <= FOG_RADIUS && dc <= FOG_RADIUS){
                g->visible[r][c]=1;
                g->explored[r][c]=1;
            }
        }
    }
}

/*
* Checks for trap at (r,c)
* Returns 1 if T, 0 if F
*
*/

int is_trap_at(const Game *g,int r, int c){
    for(int i =0;i<g->num_traps;i++){
        if(g->traps[i].x == r && g->traps[i].y==c){
            return 1;
        }
    }
    return 0;
}

/*
* Checks for treasure at (r,c)
* Returns index (0..num_treasure-1), or -1 if none.
*/
int treasure_index_at(const Game *g, int r, int c){
    for(int i =0;i<g->num_treasures;i++){
        if(g->treasures[i].x == r && g->treasures[i].y==c){
            return i;
        }
    }
    return -1;    
}

/*
* Prints our board with FOW
* Uses:
*  ? = Unseen Before
*  . = Seen before and/or is unoccupied
*  P = Player
*  $ = Visible Treasure
*  T = Visible Trap
*/

void print_board(const Game *g){
    printf("-----------------------------------------\n");
    for(int r =0;r<GRID_SIZE;r++){
        printf("|");
        for(int c =0;c<GRID_SIZE;c++){
            if(!g->explored[r][c]){
                printf(" ? |");
                continue;
            }
            if(!g->visible[r][c]){
                printf(" . |");
                continue;
            }
            if(g->player.x==r && g->player.y == c){
                printf(" P |");
            }else if(is_trap_at(g,r,c)){
                printf(" T |");
            }else{
                int ti = treasure_index_at(g,r,c);
                if(ti >= 0){
                    printf(" $ |");
                }else{
                    printf(" . |");
                }
            }
        }
        printf("\n");
    }
    printf("-----------------------------------------\n");
}

/*
* Collects the treasure
* Removes the treasure by replacing it with the last one
*/

void collect_treasure(Game *g,int index){
    g->treasures[index] = g->treasures[g->num_treasures -1];
    g->num_treasures--;
    g->score++;
}

/* 
* Moves the Player
* Handles input, movement, Fog update, treasure pickup,
* trap collision, win condition, and status messages
*/

void move(Game *g, char cmd){
    cmd = toupper(cmd);
    if(cmd != 'W' && cmd != 'A' && cmd != 'S' && cmd != 'D'){
        printf("Invalid Command\n");
        return;
    }

    int dr=0,dc=0;
    if(cmd == 'W'){
        dr=-1;
    }else if(cmd == 'S'){
        dr=1;
    }else if(cmd == 'A'){
        dc=-1;
    }else if(cmd == 'D'){
        dc=1;
    }

    int nr = g->player.x+dr;
    int nc = g->player.y+dc;

    if(!in_bounds(nr,nc)){
        printf("Out of Bounds\n");
        return;
    }

    // Apply movement
    g->player.x=nr;
    g->player.y=nc;

    update_visibility(g);

    int ti = treasure_index_at(g,nr,nc);
    if(ti >= 0){
        collect_treasure(g,ti);
        printf("Yarr Yee found dabloons!\n");
    }else if(is_trap_at(g,nr,nc)){
        printf("Yarr yee found Davey Jones's Locker. Better luck next time!\n");
        g->game_over=1;
        return;
    }else{
        printf("You moved\n");
    }

    if(g->num_treasures ==0){
        printf("Yarr Yee did it, Yee got all the dabloons on this map!\n");
        g->game_over =1;
    }
}