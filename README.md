# Rubix Cuber Solver / 解魔方大作业
The Rubik's cube is a 3D combination puzzle invented by Ernő Rubik in 1974. This project creates an efficient step-wise implementation of a 3x3 Rubik's cube solver.

Strength of our solution:
- Single write call for entire program
- No cube rotation in solving algorithms
- Dynamic programming
- Solves any given input in 0.001s
- Uses maximum 4 kilobytes of memory space.

## How it works
A cube is considered solved when each side is uniquely one color. Our program is given six 9-length strings of randomised characters that represent each face of the rubik's cube. Each letter is capitalised and symbolizes a color. Our solver proceeds to parse the input into two structures: a structure tracking the corners and a structure tracking the middle edges.
Next, the program uses various algorithms to solve the cube systemically from first layer to second to third layer. Finally, the program output a list of steps that will solve the cube. On average, the program takes approximately 150 moves for a complete solution.

Moves are shown in the following picture:

![moves](https://raw.githubusercontent.com/mgia/rubix/master/images/image.png)

## Algorithm
Our solver breaks down the solution into various algorithms that will solve different parts of the cube. Typically, we solve the edges before solving the corners of each layer.

This is our series of steps:

![cube](https://raw.githubusercontent.com/mgia/rubix/master/images/white_cross.png)
![cube](https://raw.githubusercontent.com/mgia/rubix/master/images/white_corners.png)
![cube](https://raw.githubusercontent.com/mgia/rubix/master/images/middle_layer.png)
![cube](https://raw.githubusercontent.com/mgia/rubix/master/images/yellow_cross.png)
![cube](https://raw.githubusercontent.com/mgia/rubix/master/images/complete.png)


## How to test

Git clone this repository and use the command:
```
make
```

In the command line, run the executable with six 9-length character strings as follows:
```
./a.out GGYGGYGGY WBBWBBWBB OOOOOOOOO RRRRRRRRR WWGWWGWWG YYBYYBYYB
```

The output will be a list of steps to solve the cube. An example output:
```
R R R Ri R
```

Also, we have created a test function that you can de-comment to print the co-ordinates of the cube:
`test_moves(rubik);`

Here are some other test cases that you can also try:
```
RRWGGWGGW YOOYBBYBB GGGOOOOOO BRRBRRBRR WWBWWBWWO YYRYYGYYG
GGOGGOYYY BBWBBWRRW OOWOOWOOO YRRYRRRGG GWWGWWRRG BBBBYYBYY
YGYYGYOOO RRRWBWWBW WBROOROOY OGYORRWRR GGGWWWBYB GGGBYBBYB
ROGGGWGRG BWBRBBBYR OBWOOOGOW YBYGRGYBY WRRYWRBWR OYOYYWWGO
```

## Notes
As this project was conducted purely in Mandarin, a report in Mandarin can be found in this repository for reference.

## Credits
This project would not have be possible without my awesome teammate, @AkiraChang.
