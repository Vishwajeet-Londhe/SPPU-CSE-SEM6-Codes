import heapq

def dijkstra(graph, start):
    # Distance to all nodes initially infinity
    distances = {node: float('inf') for node in graph}
    distances[start] = 0

    # Priority queue to get the node with the smallest distance
    pq = [(0, start)]

    while pq:
        current_distance, current_node = heapq.heappop(pq)

        # Skip if we already found a better path
        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight

            # If new distance is smaller, update it
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))

    return distances

# Define the graph as an adjacency list
graph = {
    'A': [('B', 4), ('C', 5)],
    'B': [('A', 4), ('C', 11), ('D', 9), ('E', 7)],
    'C': [('A', 5), ('B', 11), ('E', 3)],
    'D': [('B', 9), ('F', 2)],
    'E': [('B', 7), ('C', 3), ('F', 6)],
    'F': [('D', 2), ('E', 6)]
}

# Run Dijkstra from source node 'A'
distances = dijkstra(graph, 'A')

print("Shortest distances from A:")
for node in distances:
    print(f"{node}: {distances[node]}")