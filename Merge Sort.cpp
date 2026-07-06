//Algoritm !
void Merge(vector<int>&arr, int low, int mid, int high){
    
    vector<int>temp;
    
    int i=low;
    int j=mid+1;
    
    while(i<= mid && j<=high){
        
        if(arr[i]<= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
            
        }
        
        
    }
    while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        
    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }
    
    for(int idx=0;i<arr.size();idx++){
        
        arr[low+idx]=temp[idx];
    }
        
        
    
}
void MergeSort(vector<int>&arr, int low, int high){
    
    int mid=low+(low-high)/2;
    
    if(low<high){
        
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
    
    
}

//Algoritm 2

void Merge2(int arr[], int low, int mid, int high){
    
    int i=low;
    int j=mid+1;
    int k=low;
    
    int temp[high+11];
    
    while(i<= mid && j<=high){
        
        if(arr[i]<= arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        }else{
            temp[k]=arr[j];
            j++;
            k++;
            
        }
        
        
    }
    while(i<=mid){
            temp[k]=arr[i];
            i++;
            k++;
        }
        
    while(j<=high){
        temp[k]=arr[j];
            j++;
            k++;
    }
    
    for(int idx=low;idx<high;idx++){
        
        arr[idx]=temp[idx];
    }
        
        
    
}

void MergeSort2(int arr[], int low, int high){
    
    int mid=low+(high-low)/2;
    
    if(low<high){
        
        MergeSort2(arr,low,mid);
        MergeSort2(arr,mid+1,high);
        Merge2(arr,low,mid,high);
    }
    
    
}
