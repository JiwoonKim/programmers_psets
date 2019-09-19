/**
 *  [문제] 완주하지 못한 선수
 *         : 마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 
 *           완주하지 못한 선수의 이름을 찾기
 *           (Reference: https://programmers.co.kr/learn/courses/30/lessons/42576)
 * 
 *  * Solution
 * 
 *    (1) use hash table: O(n) time, O(n) extra space
 *        -> store all participants in hash table
 *        -> erase completed participants from hash table
 *        -> return the last remaining participant in hash table
 * 
 *    (2) sort and compare: O(n logn) time, O(1) extra space
 *        -> sort participant vector and completed vector in ascending order
 *        -> compare the two vectors' elements one-by-one in order
 *           -> if do not match, the participant is the uncompleted player
 *        -> if all match until end of completion vector, 
 *           -> last participant is the uncompleted player
 * 
 * 
 *  ** What I learned
 * 
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) use hash table
 */
string solution(vector<string> participant, vector<string> completion) {
    // 마라톤 경기에 참여한 선수 모두 해시에 저장
    unordered_map<string, int> list;
    for (string person : participant) {
        if (list.count(person) > 0) {
            list[person]++;
        } else {
            list[person] = 1;
        }
    }
    // 완주한 선수들을 대상으로 해시에서 제외
    for (string person : completion) {
        list[person]--;
        if (list[person] == 0) {
            list.erase(person);
        }
    }
    // 해시에 남은 마지막 선수 반환
    string uncompleted = list.begin()->first;
    return uncompleted;
}

/**
 *  (2) sort and compare
 */
string solution(vector<string> participant, vector<string> completion) {
    // 선수 배열과 완주 선수 배열을 정렬
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    // 선수 배열과 완수 선수 배열 비교
    int size = completion.size();
    for (int i = 0; i < size; i++) {
        // 일치하지 않는다면, 해당 선수가 완주하지 못한 선수
        if (completion[i] != participant[i])
            return participant[i];
    }
    // 마지막 선수가 완주하지 못한 선수
    return participant[size];
}