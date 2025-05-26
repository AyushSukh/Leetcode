class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> time;
        for (int i = 0; i < position.size(); i++) {
            double t = (target - position[i]) / (double)speed[i];
            time.push_back({position[i], t});
        }
        sort(time.rbegin(), time.rend());
        stack<double> st;
        for (int i = 0; i < time.size(); i++) {
            if (st.empty() || time[i].second > st.top()) {
                st.push(time[i].second);
            }
        }
        return st.size();
    }
};