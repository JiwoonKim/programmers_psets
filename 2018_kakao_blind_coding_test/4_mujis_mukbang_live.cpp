/**
 *  [4] 무지의 먹방 라이브
 *      - 각 음식을 모두 먹는데 필요한 시간이 담겨있는 배열 food_times와 네트워크 장애가 발생한 시간 K초가 주어질 때,
 *        K초가 지난 이후에 몇 번째 음식부터 다시 섭취하면 되는지를 반환하기.
 *        (음식은 주어진 순서대로 먹으며, 다음 순서의 음식을 다 먹었으면 그 다음 음식을 먹는다.
 *         K초 이내에 모든 음식을 전부 다 먹었을 경우, -1을 반환한다)
 *      - Reference: https://programmers.co.kr/learn/courses/30/lessons/42891
 * 
 *      ** 효율성 테스트에 부분 점수가 있는 문제!!
 * 
 * 
 *  * Solution
 * 
 * 
 *  ** What I learned
 * 
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  
 */
int solution(vector<int> food_times, long long k) {
    int answer = 0;
    queue<pair<int, int>> q;
    int sum = 0;
    for (int i = 1, n = food_times.size(); i <= n; i++) {
        q.push(make_pair(i, food_times[i - 1]));
        sum += food_times[i-1];
    }
    if (k >= sum) {
        return -1;
    }
    while (k--) {
        int number = q.front().first;
        int left = q.front().second - 1;
        q.pop();
        if (left > 0) {
            q.push(make_pair(number, left));
        }
    }
    return q.front().first;
}