from collections import defaultdict, deque


def valid_path_dfs(n, edges, start, end):
    # construct the graph to adj list
    adj_list = defaultdict(list)
    for u, v in edges:
        adj_list[u].append(v)
        adj_list[v].append(u)

    # DFS implementation
    def dfs(node, visited):
        if node == end:
            return True
        visited.add(node)
        for neighbor in adj_list[node]:
            if neighbor not in visited:
                if neighbor < n:  # Ensure the neighbor is within the range of nodes
                    if dfs(neighbor, visited):
                        return True
        return False

    return dfs(start, set())


def valid_path_bfs(n, edges, start, end):
    # construct the graph to adj list
    adj_list = defaultdict(list)
    for u, v in edges:
        adj_list[u].append(v)
        adj_list[v].append(u)

    # BFS implementation
    queue = deque([start])
    visited = set()
    while queue:
        node = queue.popleft()
        if node == end:
            return True
        visited.add(node)
        for neighbor in adj_list[node]:
            if neighbor not in visited:
                if neighbor < n:  # Ensure the neighbor is within the range of nodes
                    queue.append(neighbor)

    return False


if __name__ == '__main__':
    n = 3
    edges = [[0, 1], [1, 2], [2, 0]]
    start = 0
    end = 2
    print(valid_path_bfs(n, edges, start, end))  # Output: True
    print(valid_path_dfs(n, edges, start, end))  # Output: True
