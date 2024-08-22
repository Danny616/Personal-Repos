# Part 1:
# abcdef
# abdcef
# abdecf
# adbcef
# adbecf
# adebcf


# Part 2:
from collections import defaultdict, deque


def findOrder(numCourses, prerequisites):
    # Prepare the graph
    adj_list = defaultdict(list)
    indegree = {}
    for dest, src in prerequisites:
        adj_list[src].append(dest)

        # Record each node's in-degree
        indegree[dest] = indegree.get(dest, 0) + 1

    # Queue for maintaining list of nodes that have 0 in-degree
    zero_indegree_queue = deque([k for k in range(numCourses) if k not in indegree])

    topological_sorted_order = []

    # Until there are nodes in the queue
    while zero_indegree_queue:
        # Pop one node with 0 in-degree
        node = zero_indegree_queue.popleft()
        topological_sorted_order.append(node)

        # Reduce in-degree for all the neighbors
        for neighbor in adj_list[node]:
            indegree[neighbor] -= 1

            # Add neighbor to queue if in-degree becomes 0
            if indegree[neighbor] == 0:
                zero_indegree_queue.append(neighbor)

    return topological_sorted_order if len(topological_sorted_order) == numCourses else []


if __name__ == '__main__':
    numCourses = 4
    prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
    print(findOrder(numCourses, prerequisites))
