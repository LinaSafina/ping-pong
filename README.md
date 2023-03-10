# Ping Pong Game

This is a console-based ping pong game written in C, where two players can play against each other.

### Installation

1. Clone the repository.

```
git clone https://github.com/LinaSafina/ping-pong.git
```

2. Navigate to the cloned directory.

```
cd ping-pong
```

3. Run the command make to compile the game.

```
gcc -o pong pong.c
```

### How to Play

1. Start the game by running the executable file ping-pong.

```
./pong
```

2. Enter the names of both players when prompted.
3. The game starts with Player 1 serving the ball.
4. Use the following keys to control the rackets:

- Player 1: "a" to move the racket up and "z" to move the racket down.
- Player 2: "k" to move the racket up and "m" to move the racket down.
- space to skip a turn (only the ball will move)

5. During each step, only one player can move their racket. If both players try to move their rackets at the same time, the input will be ignored.
6. The game ends when one of the players scores 21 points.
7. The player with the highest score wins the game.

### Contributing

This project is open to contributions. Please feel free to submit any bug reports or feature requests in the issues section of this repository. If you'd like to contribute code, please fork the repository and submit a pull request.
