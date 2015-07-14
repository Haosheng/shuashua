/***
	56. Merge Interval
	Given a collection of intervals, merge all overlapping intervals.

	For example,
	Given [1,3],[2,6],[8,10],[15,18],
	return [1,6],[8,10],[15,18].
***/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;
    if(intervals.empty()){
        return result;
    }
    sort(intervals.begin(), intervals.end(), comp_intv);
    result.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i].start <= result.back().end){
            Interval temp(result.back().start, max(result.back().end, intervals[i].end));
            result.pop_back();
            result.push_back(temp);
        }
        else{
            result.push_back(intervals[i]);
        }
    }
    return result;
}
private:
    static bool comp_intv(Interval a, Interval b){
        return a.start<b.start;
    }
};

/***
	Similar to the 179.Largest Number problem, here we could leverage the c++ sort() function with a self-defined comparison function.

	The merge operation is trivial.
***/