from Graph import *
from queue import Queue


def BFS(graph):

    queue = Queue()
    visited = set()

    root = graph.getRoot()
    queue.put(root)
    visited.add(root)

    while not queue.empty():

        # dequeueing front element
        front = queue.get()
        print(front)

        # retrieving neighbors
        neighbors = graph.getNeighbors(front)

        for neighbor in neighbors:

            # avoiding re-visit of a node
            if neighbor not in visited:
                visited.add(neighbor)
                queue.put(neighbor)
