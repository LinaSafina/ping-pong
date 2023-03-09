#include <stdio.h>
#define MAX_SCORE 21
#define FIELD_SIZE_X 82
#define FIELD_SIZE_Y 27
#define RACKET_SIZE 3
#define INITIAL_RACKET_POSITION_Y 12;

void print_score(int score1, int score2, char arr[50], char arr2[50]);
int naming(char arr[50], char arr2[50]);

int main() {
    int racket1_x = 1, racket1_y = INITIAL_RACKET_POSITION_Y;
    int racket2_x = FIELD_SIZE_X - 1, racket2_y = INITIAL_RACKET_POSITION_Y;
    int ball_x = 3, ball_y = racket1_y + 1;
    int count = 0;
    char enter;

    char name[50];
    char name2[50];

    int player1_score = 0;
    int player2_score = 0;
    int ball_direction_x = 1;
    int ball_direction_y = 1;

    char pressed_key;
    naming(name, name2);
    getchar();

    while (1) {
        // draw filed
        for (int i = 0; i <= FIELD_SIZE_Y; i++) {
            for (int j = 0; j <= FIELD_SIZE_X; j++) {
                if (i == 0 || i == FIELD_SIZE_Y) {
                    printf("-");
                } else if (j == 0 || j == FIELD_SIZE_X) {
                    printf("|");
                } else if (j == racket1_x && i >= racket1_y && i <= racket1_y + (RACKET_SIZE - 1)) {
                    printf("|");
                } else if (j == racket2_x && i >= racket2_y && i <= racket2_y + (RACKET_SIZE - 1)) {
                    printf("|");
                } else if (i == ball_y && j == ball_x) {
                    printf("o");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        // end of draw field
        print_score(player1_score, player2_score, name, name2);

        // check if ball hits rackets
        if (ball_x == 2 && ball_y >= racket1_y && ball_y < racket1_y + 3) {
            ball_direction_x *= -1;
            if (racket1_y == ball_y) {
                ball_direction_y = -1;
            } else if (racket1_y + 1 == ball_y) {
                ball_direction_y = 0;
            } else {
                ball_direction_y = 1;
            }
        }

        if (ball_x == (FIELD_SIZE_X - 2) && ball_y >= racket2_y && ball_y < racket2_y + 3) {
            ball_direction_x *= -1;
            if (racket1_y == ball_y) {
                ball_direction_y = -1;
            } else if (racket1_y + 1 == ball_y) {
                ball_direction_y = 0;
            } else {
                ball_direction_y = 1;
            }
        }

        // check if ball hit walls
        if (ball_x == 2 && (ball_y < racket1_y || ball_y > racket1_y + 2)) {
            player2_score += 1;

            if (player2_score == MAX_SCORE) {
                printf("Congratulations, Player 2!");
                break;
            }
        }

        if (ball_x == (FIELD_SIZE_X - 2) && (ball_y < racket2_y || ball_y > racket2_y + 2)) {
            player1_score += 1;

            if (player1_score == MAX_SCORE) {
                printf("Congratulations, Player 1!");
                break;
            }
        }

        if ((ball_x == 1 && (ball_y < racket1_y || ball_y > racket1_y + 3)) ||
            (ball_x == (FIELD_SIZE_X - 1) && (ball_y < racket2_y || ball_y > racket2_y + 3))) {
            count++;
            if (count % 2 == 0 && count != 0) {
                ball_x = FIELD_SIZE_X - 3;
                ball_y = racket2_y + 1;
                ball_direction_x = -1;
            } else {
                ball_x = 3;
                ball_y = racket1_y + 1;
                ball_direction_x = 1;
            }
            ball_direction_y *= -1;
        }
        if (ball_y == 1 || ball_y == (FIELD_SIZE_Y - 1)) {
            ball_direction_y *= -1;
        }

        // check what key was pressed

        do {
            scanf("%c", &pressed_key);
            if (pressed_key != 10) {
                scanf("%c", &enter);
            }

        } while ((pressed_key != 'a' && pressed_key != 'z' && pressed_key != 'k' && pressed_key != 'm' &&
                     pressed_key != ' ' && pressed_key != 'A' && pressed_key != 'Z' && pressed_key != 'K' &&
                     pressed_key != 'M') ||
                 enter != 10);

        if (pressed_key == 'a' || pressed_key == 'A') {
            if (racket1_y - 1 != 0) {
                racket1_y--;
            }
        } else if (pressed_key == 'z' || pressed_key == 'Z') {
            if (racket1_y + 1 != (FIELD_SIZE_Y - 2)) {
                racket1_y++;
            }
        } else if (pressed_key == 'k' || pressed_key == 'K') {
            if (racket2_y - 1 != 0) {
                racket2_y--;
            }
        } else if (pressed_key == 'm' || pressed_key == 'M') {
            if (racket2_y + 1 != (FIELD_SIZE_Y - 2)) {
                racket2_y++;
            }
        }

        // //change ball's coordinates
        ball_x += ball_direction_x;
        ball_y += ball_direction_y;
    }

    return 0;
}

void print_score(int score1, int score2, char arr[50], char arr2[50]) {
    for (int i = 0; i < 33; i++) {
        printf(" ");
    }

    printf("%s %d : %d %s\n", arr, score1, score2, arr2);
}

int naming(char arr[50], char arr2[50]) {
    printf("Enter First player name: \n");
    scanf("%49s", arr);
    printf("First player: %s\n", arr);
    printf("Enter Second player name: \n");
    scanf("%49s", arr2);
    printf("Second player: %s\n", arr2);

    return 0;
}
