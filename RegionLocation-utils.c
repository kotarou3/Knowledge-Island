#include <assert.h>

#include "RegionLocation-utils.h"

bool isExistentRegion(RegionLocation location) {
    return -REGION_RADIUS <= location.x && location.x <= REGION_RADIUS &&
        -REGION_RADIUS <= location.y && location.y <= REGION_RADIUS &&
        -REGION_RADIUS <= location.x + location.y && location.x + location.y <= REGION_RADIUS;
}

bool isLandRegion(RegionLocation location) {
    return -LAND_RADIUS <= location.x && location.x <= LAND_RADIUS &&
        -LAND_RADIUS <= location.y && location.y <= LAND_RADIUS &&
        -LAND_RADIUS <= location.x + location.y && location.x + location.y <= LAND_RADIUS;
}

bool isRegionsEqual(RegionLocation a, RegionLocation b) {
    return a.x == b.x && a.y == b.y;
}

bool isRegionsAdjacent(RegionLocation a, RegionLocation b) {
    return (a.x == b.x && a.y + 1 == b.y) || // Up
        (a.x == b.x && a.y - 1 == b.y) || // Down
        (a.x - 1 == b.x && a.y + 1 == b.y) || // Up-left
        (a.x - 1 == b.x && a.y == b.y) || // Down-left
        (a.x + 1 == b.x && a.y == b.y) || // Up-right
        (a.x + 1 == b.x && a.y - 1 == b.y); // Down-right
}

RegionLocation getAdjacentRegion(RegionLocation location, Direction direction) {
    assert(direction & UP || direction & DOWN);

    RegionLocation result;
    result.x = location.x;
    result.y = location.y;

    if (direction & LEFT) {
        result.x--;
    } else if (direction & RIGHT) {
        result.x++;
    }

    if (direction == DOWN || direction == DOWN_RIGHT) {
        result.y--;
    } else if (direction == UP || direction == UP_LEFT) {
        result.y++;
    }

    return result;
}
