class FrequencyTracker {
public:
    unordered_map<int,int> m;
    unordered_map<int,int> freq;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        freq[m[number]]--;
        if ( freq[m[number]] == 0) freq.erase(m[number]);
        m[number]++;
        freq[m[number]]++;
    }
    
    void deleteOne(int number) {
        if ( m.find(number) != m.end()){
            freq[m[number]]--;
            if ( freq[m[number]] == 0) freq.erase(m[number]);
            m[number]--;
            if ( m[number] == 0 ) m.erase(number);
            else{
                freq[m[number]]++;
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        if ( freq.find(frequency) != freq.end()) return true;
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */