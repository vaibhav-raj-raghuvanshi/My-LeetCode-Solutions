class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string dateStart = max(arriveAlice, arriveBob);
        string dateEnd = min(leaveAlice, leaveBob);
        if(dateStart > dateEnd){
            return 0;
        }
        int startMonth = stoi(dateStart.substr(0, 2));
        int startDay = stoi(dateStart.substr(3, 2));
        int endMonth = stoi(dateEnd.substr(0, 2));
        int endDay = stoi(dateEnd.substr(3, 2));
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int start = startDay;
        int end = endDay;
        for(int i = 0; i < startMonth - 1; i++){
            start += days[i];
        }
        for(int i = 0; i < endMonth - 1; i++){
            end += days[i];
        }
        return end - start + 1;
    }
};