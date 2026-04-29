from Graph import *


def DFS(graph):

    stack = []
    visited = set()

    root = graph.getRoot()
    stack.append(root)
    visited.add(root)

    while stack:
        
        front = stack.pop()
        print(front)

        # retrieving neighbors
        neighbors = graph.getNeighbors(front)

        for neighbor in neighbors:

            # avoiding re-visit of a node
            if neighbor not in visited:
                visited.add(neighbor)
                stack.append(neighbor)