class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int mini = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            int ele = (landStartTime[i] + landDuration[i]);
            for (int j = 0; j < m; j++) {
                if (ele <= waterStartTime[j]) {
                    mini = min(mini, waterStartTime[j] + waterDuration[j]);
                }

                else
                    mini = min(mini, ele + waterDuration[j]);
            }
        }

        for (int i = 0; i < m; i++) {
            int ele = (waterStartTime[i] + waterDuration[i]);
            for (int j = 0; j < n; j++) {
                if (ele <= landStartTime[j]) {
                    mini = min(mini, landStartTime[j] + landDuration[j]);
                } else
                    mini = min(mini, ele + landDuration[j]);
            }
        }

        return mini ;
    }
};