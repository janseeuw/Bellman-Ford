#Bellman-Ford

Bellman-Ford is used for the shortest distances from a single source vertex.
If the graph has no negative cycles:

* The shortest paths have no negative cycles either.
* The shortest paths contain no more then V-1 edges (V = number of vertices).

## Algorithm

We do V-1 iterations, where shortest paths can become _one_ edge longer. We have to test for every vertex if the distance can become shorter. 


For typical graphs, examing every edge on every pass is wasteful. This is why we will use a queue in the implementation.
