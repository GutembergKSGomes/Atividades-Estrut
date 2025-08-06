# -*- coding: utf-8 -*-
import time
from maze import Maze
from collections import deque

def solve_maze_backtracking(maze):
    stack = deque()      
    visited = set()     

    start_pos = maze.get_init_pos_player()
    stack.append(start_pos)

    prev_pos = None  
    while stack:
        current = stack.pop()
        row, col = current

        
        if current in visited:
            continue
        visited.add(current)

        
        if prev_pos and maze.M[prev_pos[0], prev_pos[1]] == Maze.PLAYER:
            maze.M[prev_pos[0], prev_pos[1]] = Maze.HALL


        maze.mov_player(current)
        prev_pos = current
        time.sleep(0.03)  

       
        if maze.find_prize(current):
            print("🎉 Caminho encontrado até o prêmio!")
            return True

        
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        for dr, dc in directions:
            new_pos = (row + dr, col + dc)

            if maze.is_free(new_pos) and new_pos not in visited:
                stack.append(new_pos)

    print("🚫 Não foi possível encontrar o prêmio.")
    return False


maze_csv_path = "labirinto1.txt"  
maze = Maze()
maze.load_from_csv(maze_csv_path)
maze.run()
maze.init_player()


solve_maze_backtracking(maze)
