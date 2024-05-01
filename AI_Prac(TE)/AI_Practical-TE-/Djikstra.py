class Graph():
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)]
                      for row in range(vertices)]
    
    def printSolution(self, dist):
        print("Vertex \t Distance from Source")
        for node in range(self.V):
            print(node, "\t\t", dist[node])
    
    def minDistance(self, dist, sptSet):
        min_val = float('inf')
        min_index = -1
        for v in range(self.V):
            if dist[v] < min_val and not sptSet[v]:
                min_val = dist[v]
                min_index = v
        return min_index
    
    def dijkstra(self, src):
        dist = [float('inf')] * self.V
        dist[src] = 0
        sptSet = [False] * self.V
        
        for _ in range(self.V):
            u = self.minDistance(dist, sptSet)
            sptSet[u] = True
            
            for v in range(self.V):
                if (self.graph[u][v] > 0 and
                   not sptSet[v] and
                   dist[v] > dist[u] + self.graph[u][v]):
                    dist[v] = dist[u] + self.graph[u][v]
        
        self.printSolution(dist)

# Prompting user for graph input
V = int(input("Enter the number of vertices: "))
g = Graph(V)

print("Enter the adjacency matrix:")
graph_input = []
for i in range(V):
    row = list(map(int, input().split()))
    graph_input.append(row)

g.graph = graph_input

source = int(input("Enter the source vertex: "))
g.dijkstra(source)


# 0 4 0 0 0 0 0 8 0
# 4 0 8 0 0 0 0 11 0
# 0 8 0 7 0 4 0 0 2
# 0 0 7 0 9 14 0 0 0
# 0 0 0 9 0 10 0 0 0
# 0 0 4 14 10 0 2 0 0
# 0 0 0 0 0 2 0 1 6
# 8 11 0 0 0 0 1 0 7
# 0 0 2 0 0 0 6 7 0 
