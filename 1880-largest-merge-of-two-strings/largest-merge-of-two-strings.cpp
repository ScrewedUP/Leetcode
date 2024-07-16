class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge = "";
        int i = 0;
        int j = 0;
        while ( i < word1.size() && j < word2.size()){
            if ( word1[i] > word2[j] ){
                merge.push_back(word1[i]);
                i++;
            }
            else if ( word1[i] < word2[j] ){
                merge.push_back(word2[j]);
                j++;
            }
            else{
                string s1 = word1.substr(i+1,word1.size());
                string s2 = word2.substr(j+1,word2.size());
                if ( s1 > s2 ){
                    merge.push_back(word1[i]);
                    i++;
                }
                else{
                    merge.push_back(word2[j]);
                    j++;
                }
            }
        }
        cout << i << " " << j;
        if ( i <= word1.size() - 1){
            for(int k = i ; k < word1.size() ; k++){
                merge.push_back(word1[k]);
            }
        }
        if ( j <= word2.size() - 1){
            for(int k = j ; k < word2.size() ; k++){
                merge.push_back(word2[k]);
            }
        }
        return merge;
    }
};