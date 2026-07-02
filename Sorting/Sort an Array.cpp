class Solution {
public:

void merge(int l,int r,int mid,vector<int>&arr){

    int i=l;
    int j=mid+1;

    vector<int>temp;
    while(i<=mid && j<=r){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i++]);
    }

    while(j<=r){
        temp.push_back(arr[j++]);
    }

    int k=0;
    for(int i=l;i<=r;i++){
        arr[i]=temp[k++];
    }

}
void MergeSort(int l,int r,vector<int>&arr){

    if(l>=r){
        return;
    }
    int mid=l+(r-l)/2;

    MergeSort(l,mid,arr);
    MergeSort(mid+1,r,arr);

    merge(l,r,mid,arr);

}

int partition(int l,int r,vector<int>&arr){

    int pivot=arr[l];
    int i=l+1;
    int j=r;

    while(1){
        while(i<=r && arr[i]<=pivot){
            i++;
        }
        while(j>l && arr[j]>pivot){
            j--;
        }
        if(i>=j){
            break;
        }
        swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[l]);

    return j;
}

void QuickSort(int l,int r,vector<int>&arr){
    
    if(l>=r){
        return;
    }
    int p=partition(l,r,arr);
    QuickSort(l,p-1,arr);
    QuickSort(p+1,r,arr);

}

    vector<int> sortArray(vector<int>& nums) {
        
        int n=nums.size();

        MergeSort(0,n-1,nums);
        // QuickSort(0,n-1,nums);

        return nums;
    }
};