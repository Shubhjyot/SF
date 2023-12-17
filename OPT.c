#include<stdio.h>

int findOptimal(int page_reference_string[],int n,int page_frames[],int num_frames,int start_index){
    int index=-1;
    int farthest=start_index;

    for(int i=0;i<num_frames;++i){
        int j;
        for(j=start_index;j<n;++j){
            if(page_frames[i]==page_reference_string[j]){
                if(j>farthest){
                    farthest=j;
                    index=i;
                }
                break;
            }
        }
        //page not found
        if(j==n){
            return i;
        }
    }
    //if all page in mem found ahead,return farthest page
    return(index==-1)?0:index;
}

void optimal(int page_reference_string[],int n,int num_frames){
    int page_frames[num_frames];
    int page_faults=0;
    int hits=0;
    
    for(int i=0;i<num_frames;++i){
        page_frames[i]=-1;
    }

    for(int i=0;i<n;++i){
        int page=page_reference_string[i];
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
            printf("Page  Fault: ");
            int replace_index=findOptimal(page_reference_string,n,page_frames,num_frames,i+1);
            printf("%d replaces by %d\n",page_frames[replace_index],page);
            page_frames[replace_index]=page;
            page_faults++;

            printf("Current page frames: ");
            for(int j=0;j<num_frames;++j){
                printf("%d",page_frames[j]);
            }
            printf("\n");
        }
    }

    //hit ratio
    float hit_ratio=((float)(n-page_faults)/n)*100;
    printf("\nTotal Page Faults: %d",page_faults);
    printf("\nHit Ratio: %.2f%%\n",hit_ratio);
}

int main(){
    int n,num_frames;
    printf("\nEnter the number of  pages in the reference string: ");
    scanf("%d",&n);
    int page_reference_string[n];
    printf("Enter the page reference string:\n");
    for(int i=0;i<n;++i){
        scanf("%d",&page_reference_string[i]);
    }

    printf("Enter the number of page frames: ");
    scanf("%d",&num_frames);

    optimal(page_reference_string,n,num_frames);
    return 0;
}