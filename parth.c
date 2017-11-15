/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 03:53:31 by vnxele            #+#    #+#             */
/*   Updated: 2017/11/12 14:19:23 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
 
t_heapN*	newMinHeapNode(int v, int dist)
{
    t_heapN* minHeapNode = (t_heapN*) malloc(sizeof(t_heapN));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}
 
t_heap*		createMinHeap(int capacity)
{
    t_heap* minHeap =
         (t_heap*) malloc(sizeof(t_heap));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =
         (t_heapN**) malloc(capacity * sizeof(t_heapN*));
    return minHeap;
}

void	swap(t_heapN** a, t_heapN** b)
{
    t_heapN* t = *a;
    *a = *b;
    *b = t;
}
 
void	minHeapify(t_heap* minHeap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;
 
    if (left < minHeap->size &&
        minHeap->array[left]->dist < minHeap->array[smallest]->dist )
      smallest = left;
 
    if (right < minHeap->size &&
        minHeap->array[right]->dist < minHeap->array[smallest]->dist )
      smallest = right;
 
    if (smallest != idx)
    {
        t_heapN *smallestNode = minHeap->array[smallest];
        t_heapN *idxNode = minHeap->array[idx];
 
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;
 
        swap(&minHeap->array[smallest], &minHeap->array[idx]);
 
        minHeapify(minHeap, smallest);
    }
}
 
int		isEmpty(t_heap* minHeap)
{
    return minHeap->size == 0;
}
 
t_heapN*	extractMin(t_heap* minHeap)
{
    if (isEmpty(minHeap))
        return NULL;
 
    t_heapN* root = minHeap->array[0];
 
    t_heapN* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
 
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0; 
    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return (root);
}
 
void	decreaseKey(t_heap* minHeap, int v, int dist)
{
    int i = minHeap->pos[v];
 
    minHeap->array[i]->dist = dist;
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
    {
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
        swap(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
 
int		isInMinHeap(t_heap *minHeap, int v)
{
   if (minHeap->pos[v] < minHeap->size)
     return (1);
   return (0);
}
 
void	printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    int  i = 0;
	while (i < n)
	{
		printf("%d \t\t %d\n", i, dist[i]);
		i++;
	}
}
 
void	dijkstra(t_graph* graph, int src)
{
    int V = graph->V;
    int dist[V];
 
    t_heap* minHeap = createMinHeap(V);
	int v = 0;
    while (v < V)
    {
        dist[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
		v++;
    }
 
    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src]   = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
 
    minHeap->size = V;
 
    while (!isEmpty(minHeap))
    {
        t_heapN* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;
 
        t_node* crawl = graph->array[u].head;
        while (crawl != NULL)
        {
            int v = crawl->dest;
 
            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && 
                                          crawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + crawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            crawl = crawl->next;
        }
    } 
    printArr(dist, V);
}
