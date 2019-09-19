/**
 *  [3] 후보키
 *      - 릴레이션을 나타내는 문자열 배열 relation이 주어질 때, 이 릴레이션에서 후보 키의 개수를 반환하기
 *      - 단, 후보키는 단일 속성(Attribute) 또는 속성의 집합으로 존재할 수 있으나, 반드시 다음 두 성질을 만족하는 것만을 인정한다.  
 *            - 유일성(uniqueness) : 릴레이션에 있는 모든 튜플에 대해 유일하게 식별되어야 한다.
 *            - 최소성(minimality) : 유일성을 가진 키를 구성하는 속성(Attribute) 중 하나라도 제외하는 경우 유일성이 깨지는 것을 의미한다. 즉, 릴레이션의 모든 튜플을 유일하게 식별하는 데 꼭 필요한 속성들로만 구성되어야 한다. 
 *      - Reference: https://programmers.co.kr/learn/courses/30/lessons/42890
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
