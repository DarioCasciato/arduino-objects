#include <stdint.h>

class EdgeDetection
{
private:
    uint8_t* _edgeValue;
    static EdgeDetection* edgeList[10];
    static uint8_t edgeCount;

    struct edge_t
            {
                uint8_t old;
                uint8_t act;
                uint8_t edge;
                uint8_t edge_pos;
                uint8_t edge_neg;
            } Edge;
public:
    EdgeDetection(uint8_t* edgeValue);

    void updateEdge();
    static void updateEdges();

    bool getOldState();
    bool getActState();
    bool getEdge();
    bool getEdgePos();
    bool getEdgeNeg();
};

