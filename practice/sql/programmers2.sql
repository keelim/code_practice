SET @hour := -1; -- 변수 선언

SELECT (@hour := @hour + 1)                                            as HOUR,
       (SELECT COUNT(*) FROM ANIMAL_OUTS WHERE HOUR(DATETIME) = @hour) as COUNT
FROM ANIMAL_OUTS
WHERE @hour < 23

# 루시와 엘라 찾기
select animal_id, name, sex_upon_intake
from ANIMAL_INS
where name in ('Lucy', 'Ella', 'Pickle', 'Rogan', 'Sabrina', 'Mitty')
order by animal_id;

# el 이름으로 들어가는 이름 찾기

select ANIMAL_ID, NAME
from ANIMAL_INS
where ANIMAL_TYPE = 'Dog'
  and NAME LIKE '%EL%'
order by NAME;

SELECT ANIMAL_ID,
       NAME,
       IF(SEX_UPON_INTAKE LIKE '%Neutered%' OR SEX_UPON_INTAKE LIKE '%Spayed%', 'O', 'X') as '중성화'
FROM ANIMAL_INS
ORDER BY ANIMAL_ID