/***
	57. Insert Interval

	Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

	You may assume that the intervals were initially sorted according to their start times.

	Example 1:
	Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

	Example 2:
	Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

	This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        // If the intervals vector is empty then just insert newInterval and return.
        if(intervals.empty()){
            intervals.push_back(newInterval);
            return intervals;
        }

        //If the newInterval lies outside the range of intervals vector, just insert and return.
        if(newInterval.end < intervals.front().start){
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        if(newInterval.start > intervals.back().end){
            intervals.push_back(newInterval);
            return intervals;
        }

        //If the original intervals vector has only one interval, then simply merge the newInterval with it
        if(intervals.size()==1){
            Interval tmp(min(intervals[0].start,newInterval.start),max(intervals[0].end,newInterval.end));
            vector<Interval> result;
            result.push_back(tmp);
            return result;
        }

        //If the original intervals vector has multiple intervals and the newInterval lies between them
        //Then first find where should the newInterval reside, (head and tail interval), and then merge
        vector<Interval> res;
        auto head=intervals.begin();
        auto tail=prev(intervals.end());
        for(auto it=intervals.begin();it!=intervals.end();it++){
            if(it->end >= newInterval.start){
                head=it;
                break;
            } 
            res.push_back(*it);
        }
        for(auto it=head;it!=intervals.end();it++){
            if(it->start > newInterval.end){
                tail=prev(it);
                break;
            }
        }
        Interval merged(min(head->start,newInterval.start),max(tail->end,newInterval.end));
        res.push_back(merged);
        for(auto it=next(tail);it!=intervals.end();it++){
            res.push_back(*it);
        }
        return res;
    }
};

/***
	The operation is simple and coding is trivial.

	Difficult part is to consider the special cases within the first 4 if statements.
***/