# HW-1, 2 - openssl library, shared memory
## usage
* to create your own public key and a certificate - run the "create_certificate.sh" script it will create:
    * key.pem - which will contain your own uncrypted public key
    * cert.pem - your root's own self-signed sertificate
    * test_digest.txt - which will contain the fingerprint (digest) of your certificate - this will be used by my program for further validation

* run "configure.sh" to create a configuration of a project
* run "build.sh" to build the project
* run "run_producer.sh" to run the producer part of the conversation
* separately - tun "run_consumer.sh" to run the consumer part of the conversation
* for the sake of clarity - consumer input awaits refreshing for each package. producer part - does not

# how does this work
producer - generates fingerprint from the openssl library\
it splits the fingerprint into packages\
each package is sent to reciever one by one\
it sends a signal of package sent into shared protocol memory, and the package itself is read into message_box shared memory\
once the reciever reads from shared memory - protocol memory is set to recieved and thus - allowing the producer to send another package. The process keeps on going according to the amount of packages - provided in control package which itself is an invitation for consumer to start communication.

# TODO
* according to coderewiev - solve the problems detected during the first part of HW
* await codereview on the second part of HW
* Architectural:
    * encapsulate an entity responsible for protocol (DRY principle on the reciever and consumer part)
    * make better steps of the proccess, as of now there are too many sub steps

* User experience
    * make it so that there is an invitation for the recieve of the message
    * create safeguards from connection termination

