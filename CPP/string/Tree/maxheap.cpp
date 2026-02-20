#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
public:
    vector<int> heap;

    void bubbleUp(int index){
        while(index > 0){
            int parent = (index - 1) / 2;

            if(heap[index] > heap[parent]){
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else{
                break;
            }
        }
    }

    void bubbleDown(int index){
        int size = heap.size();

        while(index < size){
            int left = 2*index + 1;
            int right = 2*index + 2;
            int largest = index;

            if(left < size && heap[left] > heap[largest]){
                largest = left;
            }

            if(right < size && heap[right] > heap[largest]){
                largest = right;
            }

            if(largest != index){
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else{
                break;
            }
        }
    }

    void insert(int value){
        heap.push_back(value);
        bubbleUp(heap.size() - 1);
    }

    void deleteRoot(){
        if(heap.size() == 0) return;

        heap[0] = heap.back();
        heap.pop_back();
        bubbleDown(0);
    }

    void print(){
        for(int i : heap){
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(){
    MaxHeap h;

    h.insert(10);
    h.insert(30);
    h.insert(5);
    h.insert(20);

    cout<<"Max Heap: ";
    h.print();

    h.deleteRoot();

    cout<<"After deleting root: ";
    h.print();
}
