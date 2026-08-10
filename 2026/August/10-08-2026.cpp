class Solution
{
public:
    int maxTask(vector<int> &h, vector<int> &l)
    {
        int n = h.size();
        long long noTask = 0;
        long long taskDone = max(h[0], l[0]);
        for (int i = 1; i < n; i++)
        {
            long long prevBest = max(noTask, taskDone);
            long long newNoTask = prevBest;
            long long newTaskDone = max(prevBest + l[i], noTask + h[i]);
            noTask = newNoTask;
            taskDone = newTaskDone;
        }
        return (int)max(noTask, taskDone);
    }
};