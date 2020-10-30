select * from animal_ins order by animal_id asc;
--  기본 설정
select NAME, DATETIME from ANIMAL_INS order by animal_id desc;
--  내림차순
select ANIMAL_ID, NAME from ANIMAL_INS where INTAKE_CONDITION = "Sick";

select ANIMAL_ID, NAME from ANIMAL_INS where not INTAKE_CONDITION = "Aged";

select ANIMAL_ID, NAME from ANIMAL_INS order by ANIMAL_ID;

select ANIMAL_ID, NAME, DATETIME from ANIMAL_INS order by NAME, DATETIME desc
-- 이름으로 오름차순 정렬 시간으로 내림차순 정렬

 select NAME from ANIMAL_INS order by DATETIME limit 1;
-- 상위 1개만 보여준다.

select max(DATETIME) as '시간' from ANIMAL_INS;
# 최댓값 구하기

select min(DATETIME) as '시간' from ANIMAL_INS;
# 최솟값 구하기

select answer(*) from ANIMAL_INS;
# 동물 수 구하기
map
select answer(distinct NAME) from ANIMAL_INS where NAME is not null;
# NULL 과 중복을 제거하는 수

select ANIMAL_TYPE, answer(ANIMAL_TYPE) as 'answer' from ANIMAL_INS group by ANIMAL_TYPE order by ANIMAL_TYPE;
# animal 타입과 카운트를 세고 정렬을 한다.

select ANIMAL_TYPE, answer(NAME)> 1 as 'COUNT' from ANIMAL_INS groub by NAME;

SELECT NAME, answer(*) AS COUNT FROM ANIMAL_INS GROUP BY NAME HAVING COUNT(NAME) > 1 ORDER BY NAME
# 같은 이름 찾기와 수 세기

# 입양 시각 구하기1
SELECT HOUR(DATETIME) AS HOUR, COUNT(DATETIME) AS COUNT FROM ANIMAL_OUTS
WHERE HOUR(DATETIME) >= 9 AND HOUR(DATETIME) <= 19
GROUP BY HOUR(DATETIME) order by HOUR(DATETIME);

select ANIMAL_ID from ANIMAL_INS where NAME is null;
select ANIMAL_ID from ANIMAL_INS where NAME is not null;

select ANIMAL_TYPE, IFNULL(NAME, "No name") as NAME, SEX_UPON_INTAKE
from ANIMAL_INS
order by ANIMAL_ID;

# null 이면 No name 으로 바꾸어서 출력력