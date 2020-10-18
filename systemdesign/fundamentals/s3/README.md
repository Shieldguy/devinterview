# S3

## S3 Simple Stroage Service
```
    Amazon의 객체 스토리지 서비스 
```

## Cloud Storage의 3가지 종류
```
    1. Object: 방대한 확장성 및 메타 데이터의 특성, 계층 구조가 없고, 최소한의 정보(id, data, meta data)로 수십억 단위의 파일을 처리할 수 있음 - S3

    2. File: NAS - EFS(elastic file system)

    3. Block: DB, ERP 등은 지연 시간이 짧은 전용 스토리지 필요, DAS 또는 SAN(Storage Area Network) - EBS(Elastic Block Store)
```

## 특징
```
    단지 파일을 저장하는 스토리지 역할 뿐 아니라, 빅데이터 분석, 백업, 복구 등 데이터 기반 업무에도 사용
    높은 내구성, 손쉬운 확장성, 보안성과 편리성, 관리 유연성, 저장 가능한 객체의 개수와 저장 가능한 용량 무제한, 접속 제어 및 권한 관리 가능
    요금: 저장 용량과 데이터 전송량, HTTP 요청(Request) 개수로 책정    
```

## bucket 
```
    데이터 저장소, 웹사이트의 주소나 DNS주소를 갖기 때문에 중복되는 이름을 만들 수 없고, 모든 리전에서 유일해야함. 
    모든 S3 리전에서 유일한 이름을 가지는 S3의 최상위 폴더, 리전별로 생성. 계정 별로 100개까지 생성,버킷 안에 객체를 저장
```

## object
```
    저장 파일명, S3에 데이터가 저장되는 최소 단위입니다. 객체는 파일과 메타데이터로 구성. 하나의 크기는 1B~5TB
```

## key
```
    객체의 이름, 값(Value): 객체의 데이터
```

## Meta Data
```
    HTTP Content-Type(MIME)
    모든 데이터를 비교적 균일하게 모든 노드에 분산
```

## Storage Calss
```
    Standard에서 Glacier Deep Archive의 6가지 존재 
    https://aws.amazon.com/ko/s3/storage-classes/?nc=sn&loc=3
```
