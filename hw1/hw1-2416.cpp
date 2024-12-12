#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class FreeNode {
public:
    int start;
    int size;
    FreeNode* next{nullptr};
    FreeNode(int sstart, int sszie) : start(sstart), size(sszie) {}
};

class FreeList {
public:
    FreeNode* listStart{nullptr};
    FreeNode* listEnd;
    FreeList(queue<int>& startQueue, queue<int>& sizeQueue, vector<FreeNode*>& allNodes) {
        while (!startQueue.empty() && !startQueue.empty()) {
            FreeNode* tmp = new FreeNode(startQueue.front(), sizeQueue.front());
            allNodes.push_back(tmp);
            startQueue.pop();
            sizeQueue.pop();
            if (!listStart) {
                listStart = tmp;
                listEnd = listStart;
                continue;
            }
            listEnd->next = tmp;
            listEnd = tmp;
        }
    }
    void allocate(int size) {
        if (!listStart) return;
        if (listStart->size > size) {
            listStart->start += size;
            listStart->size -= size;
            return;
        }
        if (listStart->size == size) {
            FreeNode* tmp = listStart;
            listStart = tmp->next;
            return;
        }
        FreeNode* tmpPtPrev = listStart;
        FreeNode* tmpPt = tmpPtPrev->next;
        while (tmpPt) {
            if (tmpPt->size > size) {
                tmpPt->start += size;
                tmpPt->size -= size;
                return;
            }
            if (tmpPt->size == size) {
                tmpPtPrev->next = tmpPt->next;
                return;
            }
            tmpPtPrev = tmpPt;
            tmpPt = tmpPt->next;
        }
    }
    void release(int start, int size, vector<FreeNode*>& allNodes) {
        FreeNode* toBeReleased = new FreeNode(start, size);
        allNodes.push_back(toBeReleased);
        if (!listStart) listStart = toBeReleased;
        if (toBeReleased->start < listStart->start) {
            toBeReleased->next = listStart;
            listStart = toBeReleased;
            return;
        }
        FreeNode* tmp = listStart;
        while (tmp->next) {
            if (toBeReleased->start <= tmp->next->start) {
                toBeReleased->next = tmp->next;
                tmp->next = toBeReleased;
                return;
            }
            tmp = tmp->next;
        }
        listEnd->next = toBeReleased;
        listEnd = toBeReleased;
    }
    void printList() const {
        if (!listStart) return;
        FreeNode* curNode = listStart;
        while (curNode) {
            if (curNode->size == 0) {
                curNode = curNode->next;
                continue;
            }
            FreeNode* tmp = curNode->next;
            while (tmp && curNode->start + curNode->size >= tmp->start) {
                curNode->size = tmp->start + tmp->size > curNode->start + curNode->size ? tmp->start + tmp->size - curNode->start : curNode->size;
                tmp = tmp->next;
            }
            cout << "(" << curNode->start << "," << curNode->size << ") " << flush;
            curNode = tmp;
        }
        cout << endl;
    }
};

int main() {
    int n, tmp, m;
    vector <FreeNode*> allNodes;
    queue<int> startQueue, sizeQueue;
    cin >> n;
    for (int i{0}; i < n; i++) {
        cin >> tmp;
        startQueue.push(tmp);
    }
    for (int i{0}; i < n; i++) {
        cin >> tmp;
        sizeQueue.push(tmp);
    }
    FreeList freeList = FreeList(startQueue, sizeQueue, allNodes);
    cin >> m;
    for (int i{0}; i < m; i++) {
        int opNum, op1, op2;
        cin >> opNum;
        switch (opNum) {
            case 1:
                cin >> op1;
            freeList.allocate(op1);
            break;
            case 2:
                cin >> op1 >> op2;
            freeList.release(op1, op2, allNodes);
            break;
        }
    }
    freeList.printList();
    for (auto node : allNodes) {
        delete(node);
    }
    return 0;
}