# Distributed Transaction

## 문제점
 - Transaction은 ACID가 중요(Atomicity, Consistency, Isolation, Durability)
 - 단일 DB에서 트랜잭션가 아닌 여러개 리소스를 묶어서 하나의 트랜젝션을 처리하는 경우는 어떻게 처리?

![customer order example](https://developers.redhat.com/blog/wp-content/uploads/2018/09/Untitled-UML-4.png)

## 해결책
 - 2PC
 - Saga

### 2PC
 - coordinator가 중간에서 중재해서 일관성 보장
 - but,
 - 2PC coordinator = single point of failure
 - at least O(4n) messages, with retries O(n^2)
 - Blocking. Reduced throughput due to locks
 - Not supported by many NoSql databases
 - Consistency 를 얻고 Availability 좀 포기 [CAP Theorem 참고](https://en.wikipedia.org/wiki/CAP_theorem)
 - Microservice architecture에서는 DB는 각 개별 서비스간에 따로 가지고 있어서, DB Link 같은건 무리

 ![2PC](https://developers.redhat.com/blog/wp-content/uploads/2018/09/Untitled-UML-6.png)
 ![2PC Fail](https://developers.redhat.com/blog/wp-content/uploads/2018/09/Untitled-UML-7.png)

### Saga
 - 서비스 개별적으로 로컬 트렌젝션 처리하고 결과를 도메인 이벤트로 전달
 - but, 디버깅 어려움
 - 메시지도 보내고 local transaction도 처리하면 2PC -> Transactional Outbox

 ![Saga](https://chrisrichardson.net/i/sagas/From_2PC_To_Saga.png)
 ![Choreography-based saga](https://chrisrichardson.net/i/sagas/Create_Order_Saga.png)
 ![Orchestration-based saga](https://chrisrichardson.net/i/sagas/Create_Order_Saga_Orchestration.png)

## References
 - [Oracle: Distributed Transactions Concepts](https://docs.oracle.com/cd/B19306_01/server.102/b14231/ds_txns.htm#CHDCFICE)
 - [Pattern: Saga](https://microservices.io/patterns/data/saga.html)
 - [Pattern: Transactional outbox](https://microservices.io/patterns/data/transactional-outbox.html)
 - [Handling Distributed Transactions in the Microservice world](https://medium.com/swlh/handling-transactions-in-the-microservice-world-c77b275813e0)
 - [Using sagas to maintain data consistency in a microservice architecture by Chris Richardson](https://www.youtube.com/watch?v=YPbGW3Fnmbc)
 - [Patterns for distributed transactions within a microservices architecture](https://developers.redhat.com/blog/2018/10/01/patterns-for-distributed-transactions-within-a-microservices-architecture/)
 - [클라우드에서 트랜잭션 관리 > 1부, 트랜잭션의 기초 및 분산 트랜잭션](https://developer.ibm.com/kr/cloud/2017/08/11/%ED%8A%B8%EB%9E%9C%EC%9E%AD%EC%85%98%EC%9D%98-%EA%B8%B0%EC%B4%88-%EB%B0%8F-%EB%B6%84%EC%82%B0-%ED%8A%B8%EB%9E%9C%EC%9E%AD%EC%85%98/)
 - [클라우드에서 트랜잭션 관리 > 2부, 분산 트랜잭션 없이 사용하기](https://developer.ibm.com/kr/developer-%EA%B8%B0%EC%88%A0-%ED%8F%AC%EB%9F%BC/2017/08/14/%EB%B6%84%EC%82%B0-%ED%8A%B8%EB%9E%9C%EC%9E%AD%EC%85%98-%EC%97%86%EC%9D%B4-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0/)
