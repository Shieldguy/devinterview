
# Mysql 크기 한계

### * 최대 크기: 64TB
```
최대 256 TB, but
하드웨어 및 OS와 MySQL의 선호되는 엔진 InnoDB와 함께 table 크기 제한은 64TB
AWS Aurora cluster volumes도 64TB
 - AWS Aurora cluster volumes automatically scale as the amount of data in your database increases, up to a maximum of 64 tebibytes

cf. http://mysql.rjweb.org/doc.php/limits#general_limits
```

### * 샤딩과 파티셔닝
```
Sharding?
- 샤딩은 행별로 데이터의 저장 위치를 변경하는 구조를 말한다.
- 각 샤드의 스키마 구조는 같다. 다른 것은 데이터의 내용이다.
애플리케이션은 ID나 지역 등을 기준으로 데이터를 어느 샤드에 저장하는지를 판별한다.
이 판별 로직을 애플리케이션에서 구현해야 한다.
갱신 처리 성능 향상에 한계가 있을 때 샤딩을 검토할 수 있다.

파티션이라는 단어는 여러 DB에서 다른 용어로 쓰이고 있다.
파티션은 몽고DB, 엘라스틱서치, 솔라클라우드의 샤드(shard)에 해당한다.
cf. https://johngrib.github.io/wiki/sharding/#%EB%AC%B8%EC%A0%9C%EC%A0%90
    https://umbum.dev/969
```

```
* 종류: 
 - Partitioning by Key Range
 - Partitioning by Hash of Key

* 한계:
여러 샤드를 넘나드는 쿼리를 실행할 수 없다.
해당 DB 서버 내부의 데이터만 join할 수 있다.
각각의 샤드는 같은 구조의 스키마를 갖지만, 자동으로 동기화되지는 않는다는 점에 주의.
스키마 구조를 변경하려면 DBA가 모든 샤드에 적용해줘야 한다.
불행히도 Oracle, PostgreSQL, MySQL과 같은 모 놀리 식 데이터베이스와 
Amazon Aurora와 같은 최신 분산 SQL 데이터베이스는 자동 샤딩을 지원하지 않는다. 
즉, 이러한 데이터베이스를 계속 사용하려면 응용 프로그램 계층에서 수동 분할을 수행해야함. 
그 결과 개발 복잡성이 엄청나게 증가함. 

cf. https://blog.yugabyte.com/how-data-sharding-works-in-a-distributed-sql-database/
    https://dba.stackexchange.com/questions/181503/mongodb-enable-sharding-automatically
```

### * primary key across multiple database
```
다중(분산) DB에서의 primary key 관리 방안
  - sequence 배분
  - key 채번 table 관리
  - UUID
  - key 포맷: instance_id + ‘_’ + sequence

cf. https://dba.stackexchange.com/questions/232120/how-to-generate-globally-unique-ids-for-different-tables-of-the-same-database

```

### *Aurora 멀티 마스터 클러스터 작업 in AWS
```
- 단일 마스터 클러스터(일반적인 유형):
    1개의 writer
    n개의 reader
- 멀티 마스터 클러스터
    n개의 writer and reader
    => 라이터 DB 인스턴스가 사용 불가 상태가 될 때 어떤 장애 조치도 없음
    => 데이터베이스 쓰기 작업에서 짧은 가동 중지도 허용할 수 없는 애플리케이션
    => 클러스터의 모든 DB 인스턴스가 공유 스토리지 볼륨을 통해 모든 데이터베이스 및 테이블에 액세스할 수 있기 때문에 리샤딩 작업을 피할 수 있음.
    => 읽기 작업에서 보이는 데이터에서는 복제 지연(보통 몇 밀리초)이 발생. 동일한 데이터가 다른 DB 인스턴스에서 동시에 수정

- primary key across multiple database in 멀티 마스터 클러스터,
  => 자동 증분 열 사용 in 멀티 마스터 클러스터
    이 값들은 불연속.
    빈 테이블에서는 값이 1부터 시작하지 않을 수 있음.
    1보다 큰 증분값에 따라 값이 증가.
    단일 마스터 클러스터에서보다 훨씬 신속하고 대대적으로 값이 사용.

    +----+-------+
    | id | s     |
    +----+-------+
    |  2 | row 1 |
    | 18 | row 2 |
    | 34 | row 3 |
    +----+-------+

cf. https://docs.aws.amazon.com/ko_kr/AmazonRDS/latest/AuroraUserGuide/aurora-multi-master.html#aurora-multi-master-overview

```

### * Aurora cluster 분산 db 지원 
```
잠금 읽기를 사용할 수 있음 ( SELECT … FOR UPDATE, SELECT … LOCK IN SHARE MODE).

cf. https://idk.dev/building-globally-distributed-mysql-applications-using-write-forwarding-in-amazon-aurora-global-database/

```
