# Apache Kafka

## What is the Kafka
- Developed by LinkedIn
- Distributed messaging service system
![Kafka Architecture](./kafka1.png)
![Kafka Service](./kafka2.png)

## What is the Message queue system
- Asynchronous message queue system on distribution system environment
- Publish/Subscribe model
- AMQP(Advanced Message Queuing Protocol) standard : open standard applicaition layer protocol for message-oriented middleware
  - Producers -> ( Exchange -> Binding -> Queue ) -> Consumer
  - Bindings : Direct exchange, Fanout exchange, Topic exchange, Header exchange
    - Direct exchange
![Direct exchange](./amqp1.png)
    - Topic exchange
![Topic exchange](./amqp2.png)

- Kafka, RabbitMQ, ActiveMQ (Amazon), ZeroMQ, Amazon SQS ....

## Special feature
- Multi producer, multi consumer
- Topic -> partition : pararelle process, can't quarantee squencial processing on consumer
  - Partition
![Partition](./kafka3.png)
  - Consumer group
![Partition and consumer group](./kafka4.png)
  - Service flow
![Service flow](./kafka5.png)
- Not support AMQP
- Store message to filesystem.
- High throughput than others
- Message pull from broker
- Un-distrupted scale out support

## System architecture
- Publisher(Producer) -(message)-> ( Broker -> Topic -> Partition ) <-(pull)- Subscriber(Consumer, Group)
                            +----> ( Broker +        +> Partition ) <---+

## Check point
- Message processing order : not quarntee with multi partition
- Partition count : performance vs resource
- Topic store period : resource
...

## Usage
- Uber
![Uber](./kafka6.png)

