class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double median = 0.0;
        
        int index1 = 0;
        int index2 = 0;
        
        int total_length = nums1.size() + nums2.size();
        if (total_length % 2 == 0) {
            // even
            int counter = total_length / 2 + 1;
            while(counter > 0) {
                
                int min1 = (index1 < nums1.size()) ? nums1[index1] : INT_MAX;
                int min2 = (index2 < nums2.size()) ? nums2[index2] : INT_MAX;
                
                int value = 0;
                if (min1 < min2) {
                    value = min1;
                    ++index1;
                } else {
                    value = min2;
                    ++index2;
                }
                  
                if (counter == 2 || counter == 1)
                    median += value;
                
                --counter;
            }
            return median / 2.0;
            
        } else {
            // odd
            int counter = total_length / 2 + 1;
            while (counter > 0) {
                
                int min1 = (index1 < nums1.size()) ? nums1[index1] : INT_MAX;
                int min2 = (index2 < nums2.size()) ? nums2[index2] : INT_MAX;
                
                int value = 0;
                if (min1 < min2) {
                    value = min1;
                    ++index1;
                } else {
                    value = min2;
                    ++index2;
                }
                
                if (counter == 1)
                    return value;    
                
                --counter;
            }   
        }
    }
};