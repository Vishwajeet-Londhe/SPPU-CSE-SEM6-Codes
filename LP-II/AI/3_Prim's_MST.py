import sys

class Graph():
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)]
                      for row in range(vertices)]

    def printMST(self, parent):
        print("Edge \tWeight")
        total_weight = 0
        for i in range(1, self.V):
            weight = self.graph[parent[i]][i]
            print(parent[i] + 1, "-", i + 1, "\t", weight)
            total_weight += weight
        print("Total weight of MST:", total_weight)

    def minKey(self, key, mstSet):
        min = sys.maxsize
        min_index = -1

        for v in range(self.V):
            if key[v] < min and not mstSet[v]:
                min = key[v]
                min_index = v

        return min_index

    def primMST(self):
        key = [sys.maxsize] * self.V
        parent = [None] * self.V
        key[0] = 0
        mstSet = [False] * self.V
        parent[0] = -1

        for _ in range(self.V):
            u = self.minKey(key, mstSet)
            mstSet[u] = True

            for v in range(self.V):
                if self.graph[u][v] > 0 and not mstSet[v] and key[v] > self.graph[u][v]:
                    key[v] = self.graph[u][v]
                    parent[v] = u

        self.printMST(parent)

if __name__ == '__main__':
    g = Graph(6)
    g.graph = [
        [0, 2, 0, 1, 4, 0],  # Node 1
        [2, 0, 3, 0, 0, 7],  # Node 2
        [0, 3, 0, 5, 0, 8],  # Node 3
        [1, 0, 5, 0, 9, 0],  # Node 4
        [4, 0, 0, 9, 0, 0],  # Node 5
        [0, 7, 8, 0, 0, 0]   # Node 6
    ]

    g.primMST()