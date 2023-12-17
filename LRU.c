#include<stdio.h>

void lru(int pag_reference_string[],int n,int num_frames){
    int page_frames[num_frames];
    int page_faults=0;
    int hits=0;
    int counter[num_frames];
    int time=0;

    for(int i=0;i<num_frames;++i){
        page_frames[i]=-1;
        counter[i]=0;
    }

    for(int i=0;i<n;++i){
        int page=pag_reference_string[i];
        int page_found=0;

        for(int j=0;j<num_frames;++j){
            if(page_frames[j]==page){
                printf("Page %d is already in memory(hit)\n",page);
                hits++;
                page_found=1;
                break;
            }
        }

        if(!page_found){
            printf("Page Fault: ");
            int min_count=counter[0];
            int replace_index=0;

            for(int j=1;j<num_frames;++j){
                if(counter[j]<min_count){
                    min_count=counter[j];
                    replace_index=j;
                }
            }

            printf("%d replaced by %d\n",page_frames[replace_index],page);
            page_frames[replace_index]=page;
            page_faults++;

            counter[replace_index]=time;

            printf("Current page frames: ");
            for(int j=0;j<num_frames;++j){
                printf("%d",page_frames[j]);
            }
            printf("\n");
        }

        for(int j=0;j<num_frames;++j){
            if(page_frames[j]!=-1){
                counter[j]++;
            }
        }
        counter[page]=0;
        time++;
    }
    printf("\nTotal Page Faults: %d",page_faults);
    printf("\nHit Ratio:%.2f%%\n",((float)hits/n)*100);
}

int main(){
    int n,num_frames;
    printf("Enter the number of pages in the reference string: ");
    scanf("%d",&n);
    int pag_reference_string[n];
    printf("\nEnter the page reference string: ");
    for(int i=0;i<n;++i){
        scanf("%d",&pag_reference_string[i]);
    }

    printf("\nEnter the number of page frames: ");
    scanf("%d",&num_frames);

    lru(pag_reference_string,n,num_frames);
    return 0;
}