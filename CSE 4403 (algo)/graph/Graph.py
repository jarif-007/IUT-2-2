class Graph:
    def __init__(self, points):

        self.adj_list = {}

        for u, v in points:

            if u not in self.adj_list:
                self.adj_list[u] = []

            if v not in self.adj_list:
                self.adj_list[v] = []

            self.adj_list[u].append(v)
            self.adj_list[v].append(u)

    def getRoot(self):
        return next(iter(self.adj_list))

    def getNeighbors(self, node):
        return self.adj_list[node]
