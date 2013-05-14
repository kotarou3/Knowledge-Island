#ifndef VERTEXLOCATION_UTILS_H
#define VERTEXLOCATION_UTILS_H

#include "Game-redefines.h"
#include "Map.h"

#define VERTEX_LEFT 0 // Left of a region
#define VERTEX_RIGHT 1 // Right of a region
typedef unsigned char VertexType;

bool isValidVertex(VertexLocation location);
bool isVerticesEqual(VertexLocation a, VertexLocation b);
VertexType getVertexType(VertexLocation location);

#define NUM_SURROUNDING_VERTICES_FROM_REGION 6
typedef struct _SurroundingVerticesFromRegion {
    VertexLocation locations[NUM_SURROUNDING_VERTICES_FROM_REGION];
} SurroundingVerticesFromRegion;
SurroundingVerticesFromRegion getSurroundingVerticesFromRegion(RegionLocation location);

#define NUM_SURROUNDING_VERTICES_FROM_VERTEX 3
typedef struct _SurroundingVerticesFromVertex {
    VertexLocation locations[NUM_SURROUNDING_VERTICES_FROM_VERTEX];
} SurroundingVerticesFromVertex;
SurroundingVerticesFromVertex getSurroundingVerticesFromVertex(VertexLocation location);

#endif
