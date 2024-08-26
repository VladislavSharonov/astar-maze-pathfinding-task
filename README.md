# Maze pathfinding.

The application prints the path in the maze (**input.txt**).
Movement along the path is only horizontal and vertical.

Legend:

*"S" - start*

*"." - free space*

*"F" - finish*

*"x" - wall*

*"\*" - path*

Input example (input.txt):

    S..xx..xxx
    ...xx..xx.
    ...x..x.x.
    xx...xx..x
    xxx.......
    ......xxxF
    ......xxx.

Output (stdout):

    S..xx..xxx
    *..xx..xx.
    ***x..x.x.
    xx**.xx..x
    xxx*******
    ......xxxF
    ......xxx.
