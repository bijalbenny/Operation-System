
#include <stdio.h>

int frames[10];
int pages[50];
int frame_usage[10];

int findLRU(int n_frames) {
    int min = frame_usage[0];
    int pos = 0;
    for (int i = 1; i < n_frames; i++) {
        if (frame_usage[i] < min) {
            min = frame_usage[i];
            pos = i;
        }
    }
    return pos;
}

void main() {
    int no_of_frames, no_of_pages, page_hit = 0, page_fault = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter the number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter the reference string: ");
    for (int i = 0; i < no_of_pages; i++) {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < no_of_frames; i++) {
        frames[i] = -1;
        frame_usage[i] = 0;
    }

    printf("Page\tFrames\n");
    for (int i = 0; i < no_of_pages; i++) {
        int page = pages[i];
        int flag = 0;

        for (int j = 0; j < no_of_frames; j++) {
            if (frames[j] == page) {
                frame_usage[j] = i + 1; // Update usage count
                flag = 1; // Page hit
                break;
            }
        }

        if (flag == 0) { // Page fault
            int lru_pos = findLRU(no_of_frames);
            frames[lru_pos] = page;
            frame_usage[lru_pos] = i + 1; // Update usage count
            page_fault++;
        } else {
            page_hit++;
        }

        printf("%d\t", page);
        if (flag == 1) {
            printf("page hit\n");
        } else {
            for (int j = 0; j < no_of_frames; j++) {
                if (frames[j] == -1) {
                    printf("-\t");
                } else {
                    printf("%d\t", frames[j]);
                }
            }
        }
        printf("\n");
    }

    printf("Page fault: %d\n", page_fault);
    printf("Page hit: %d\n", page_hit);

}
