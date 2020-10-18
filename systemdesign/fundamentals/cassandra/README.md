# 카산드라

## 카산드라
```
    페북->아파치
    NoSQL 데이터베이스의 한 종류
```

## 데이터모델
```
    Key space > Table > Row > column name : column value
    SET, LIST, MAP 도 칼럼에 저장 가능

    cf)
    Cassandra : Key-space > Table > Row > Column name : Column value
    Mongodb : db > collection > document > key:value
    RDBMS : DB > Table > row > column
    elasticsearch : index > type> document > key : value
```

## 특징
```
    하나의 row는 여러개의 column
    각각의row가 같은 수의 column을 가질 필요는 없다. (Sparse Multidimensional Hash Table) => schemeless
    각 row는 unique key를 가진다. partitioning에 사용됨.
    No relational => join 불가
    Map< RowKey, SortedMap<ColumnKey, ColumnValue> >
```

## CQL(Cassnadra Query Language) 
```
    SQL과 비슷한 쿼리 인터페이스
    CREATE TABLE , INSERT, SELECT 등 거의 유사함.
```

## keys
```
    - primary key: 1개이상의 partition key와 0개이상의 cluster key로 구성
    - partition key: data를 분산 저장하기 위한 unique한 key
    - cluster key: 정렬에 대한 기준 
```

## Cassandra Ring
```
    - Gossip 프로토콜을 통하여 모든 노드가 동등한 Ring 구조
    - Ring을 구성하는 각 노드에 Data를 분산하여 저장
    - spreads a multicast quickly
    - highly fault-tolerant
```

## 분산 (Shard)
```
    카산드라는 마스터 없이 동작한다.
    모든 데이터를 비교적 균일하게 모든 노드에 분산
```

## INDEX (인덱스)
```
    Indexing 된 칼럼이 아니라면, 카산드라는 해당 칼럼을 가지고 filter 할 수 없다.
    (그게 primary key가 아니면 말이다.)
```

## Distributed and Decentralized
```
    Distributed Muliple machines 에서 작동 가능하도록 최적화 되어있다.
    Decentralized : 모든 노드가 동등하다.(Every node is identical)
    노드 간에 Master-Slave 관계가 없다.
    그래서 확장하기가 쉽다. (50 개의 노드를 하는 것과 1개 노드를 하는 것이 크게 다르지 않다.)
    Any node(그 어떤 노드)에서나 Read / write를 수행가능.
```

## Elastic Scalability (탄력적 확장성)
```
    Scalability (확장)
    성능저하가 거의 없이 시스템이 방대한 양의 request를 처리할 수 있도록 하는 구조적 기능.
    매끄럽게 Horizontally scale up과 scale back down이 가능.
    즉, node 수를 추가하고 감소시키는 것이 쉽다. 매끄럽다
```
## High Availability and Fault Tolerance
```
    Availability(가용성) 란? : 모든 DB 클라이언트는 항상 데이터 읽기와 쓰기가 가능해야한다.
    Failed nodes 를 downtime(컴퓨터가 작동을 멈추는 시간) 없이 교체할 수 있다. 이는 모든 노드가 동등한 구조 덕분.
    No single point of failure due to the p2p architecture
```

## High Performance
```
    더 많은 서버를 추가 할때 성능을 저하시키지 않는다.
    모든 disk write이 Sequential이다. (append only operation)
    (참고) - Cassandra 가 MySQL보다 빠른 이유 : lookup 하지 않고 그저 write 만 하기 때문
    no reading before writing
```

## Tunable Consistency
```
    같은 시점의 requests 에 대해 동일한 결과(가장 최신 결과)를 리턴해야 하지만,
    카산드라는 전체 Availability(가용성)을 높이기 위해 Consistency(일관성)을 약간 희생한다.
    Consistency Level을 조정해서 Availability 와의 균형을 조정할 수 있다. *High Available 이냐 Strong Consistency냐
```

## 장단점
```
    장점) 
        속도, 확장성
    단점)
        복잡한 조건 검색이 불가능하다.
        데이터 갱신 및 입력시 Atomic한 처리가 어렵다.
```

## 누가 사용하는가
```
    Twitter : 분석 용도로 사용  => ?
    Mahalo : 실시간에 가까운 데이터 저장소로 사용   => ㅇ
    Facebook : 받은 편지함 검색에 사용   => ㅇ
    Digg : 거의 실시간에 가까운 데이터 저장소로 사용   => ㅇ
    Rackspace : 클라우드 서비스, 모니터링, 로깅에 사용   => ㅇ
    Reddit : 영속적인 캐시로 사용   => ㅇ
    Cloudkick : 통계 및 분석 모니터링에 사용   => ?
    Ooyala : 거의 실시간에 가까운 비디오 분석 데이터 서비스와 저장에 사용   => ?
    SimpleGeo : 실시간 위치 인프라 스트럭처를 위한 주 데이터 저장소로 사용   => ㅇ
    Onespot : 주 데이터 저장소의 서비스셋으로 사용   => ㅇ
```

    cf) https://nicewoong.github.io/development/2018/02/11/cassandra-feature/

## 설치 및 활용
    https://weejw.tistory.com/255?category=798588
