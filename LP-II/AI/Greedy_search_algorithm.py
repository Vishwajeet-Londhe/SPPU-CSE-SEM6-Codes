import heapq

def greedy_search(graph, start, goal, heuristic):
    visited = set()
    queue = []

    # Priority queue with tuples: (heuristic_cost, node, path)
    heapq.heappush(queue, (heuristic[start], start, [start]))

    while queue:
        cost, current, path = heapq.heappop(queue)

        if current == goal:
            return path

        if current in visited:
            continue
        visited.add(current)

        for neighbor in graph.get(current, []):
            if neighbor not in visited:
                heapq.heappush(queue, (heuristic[neighbor], neighbor, path + [neighbor]))

    return None  # If no path is found

# Sample graph (adjacency list)
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

# Heuristic values (h(n)): estimated cost from each node to goal 'F'
heuristic = {
    'A': 3,
    'B': 2,
    'C': 1,
    'D': 6,
    'E': 1,
    'F': 0
}

# Define start and goal nodes
start_node = 'A'
goal_node = 'F'

# Run Greedy Search
result = greedy_search(graph, start_node, goal_node, heuristic)

# Output the result
print("Path found by Greedy Search:", result)