#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findFarthestPage(vector<int>& pages, vector<int>& frame, int start, int end) {
    int farthestPage = -1;
    int farthestIndex = -1;
    for (int i = 0; i < frame.size(); i++) {
        int j;
        for (j = start; j < end; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthestIndex) {
                    farthestIndex = j;
                    farthestPage = frame[i];
                }
                break;
            }
        }
        if (j == end) {
            return i;
        }
    }

 return (farthestPage == -1) ? 0 : farthestPage;
}


int optimalPageReplacement(vector<int>& pages, int frameSize) {
    vector<int> frame(frameSize, -1);
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
 
        if (find(frame.begin(), frame.end(), pages[i]) != frame.end()) {
            continue;
        }
      int emptySlotIndex = find(frame.begin(), frame.end(), -1) - frame.begin();
        if (emptySlotIndex != frameSize) {
            frame[emptySlotIndex] = pages[i];
        } else {
          int pageToReplace = findFarthestPage(pages, frame, i + 1, pages.size());
            frame[pageToReplace] = pages[i];
        }

        pageFaults++;
    }

    return pageFaults;
}

int main() {
    int pageCount, frameSize;
    cout << "Enter the number of pages: ";
    cin >> pageCount;
    cout << "Enter the frame size: ";
    cin >> frameSize;
   vector<int> pages(pageCount);

    cout << "Enter the page reference string: ";
    for (int i = 0; i < pageCount; i++) {
        cin >> pages[i];
    }
    int pageFaults = optimalPageReplacement(pages, frameSize);
   cout << "Total page faults: " << pageFaults << endl;
   return 0;
}