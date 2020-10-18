
## Elasticsearch
```
    Apache Lucene( 아파치 루씬 ) 기반의 Java 오픈소스 분산 검색 엔진
```

### ELK stack
```
    ELK( Elasticsearch / Logstatsh / Kibana )스택
    
    Logstash
        다양한 소스( DB, csv파일 등 )의 로그 또는 트랜잭션 데이터를 수집, 집계, 파싱하여 Elasticsearch로 전달
    Elasticsearch
        Logstash로부터 받은 데이터를 검색 및 집계를 하여 필요한 관심 있는 정보를 획득
    Kibana
        Elasticsearch의 빠른 검색을 통해 데이터를 시각화 및 모니터링
```

<img srcset="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&amp;fname=http%3A%2F%2Fcfile22.uf.tistory.com%2Fimage%2F998444375C98CC021F2221" src="https://t1.daumcdn.net/cfile/tistory/998444375C98CC021F" style="cursor: pointer;max-width:100%;height:auto" width="669" height="242" filename="5.jpg" filemime="image/jpeg">

<img class="lb-image" src="https://t1.daumcdn.net/cfile/tistory/99E0A9425C98CF7A0A?download" style="width: 535px; height: 393px;">

## Elasticsearch 특징
```
    Scale out
        샤드를 통해 규모가 수평적으로 늘어날 수 있음
    고가용성
        Replica를 통해 데이터의 안정성을 보장
    Schema Free
        Json 문서를 통해 데이터 검색을 수행하므로 스키마 개념이 없음
    Restful
        데이터 CURD 작업은 HTTP Restful API를 통해 수행하며, 각각 다음과 같이 대응합니다.
```
### Elasticsearch 구조
```
    physical
        cluster -> Node -> Indice -> Shard
    logical
        Index -> Type -> Document -> field : value
    cluster
        노드의 집합
        클러스터 내 포함된 노드로 통합 인덱싱 및 검색 기능 제공
```

### 노드 종류
```
    마스터 노드: 전체 클러스터의 상태에 대한 메타 정보를 관리하는 노드.
        기존의 마스터 노드가 종료되는 경우, 새로운 마스터 노드가 선출 된다. 
    데이터 노드: 색인된 데이터를 실제로 저장하는 노드.
```

## Logstash
```
    Input -> Filter > Output의 pipeline 구조.
```
### Logstash의 장점
```
    - 수평확장이 가능한 데이터 처리 파이프라인
    - 플러그형 파이프라인 아키텍쳐 (입출력,필터를 믹스매치하고 조정)
    - 개발자에게 편리한 Plug-in eco system
    - 모든 형태 및 규모의 데이터를 환영
```

### Logstash Inputs
```
    - Network(TCP/UDP) : 가장 일반적.
    - syslog/rsyslog
    - Kafka, RabbitMQ, Redis
    - stdin
    - Email(IMAP)
    - Lumberjack
    - Amazon S3, gelf, collectd, gangla, sqs 등등
```

### Logstash Filters
```
    - grok : 패턴 매칭을 사용해서 추출
    - data : 필드로부터 timestamp 파싱함
    - mutate : Event -> Field를 rename, remove, replace, modify
    - csv : csv 데이터 형태로 파싱
    - geoip : ip addr로 지리를 판단
    - kv : 이벤트데이터에서 key-value 쌍을 파싱함.
    - ruby : 파이프라인에서의 모호한 Ruby code 실행될 때 등등
```

### Logstash Outputs
```
    - 저장 (Storage) : Elastcisearch, MongoDB, S3, File 등 
    - 알림 (Notification) : pagerduty, nagios, zabbix, email 등 
    - Realy : Tcp,Kafka,Redis,RabbitMQ,syslog
    - Metric : Graphite, Ganglia StatsD
```

## 키바나
```
    Kibana는 Elasticsearch 데이터를 시각화하고 Elastic Stack을 탐색하게 해주는 무료 오픈 소스 인터페이스입니다.
```
