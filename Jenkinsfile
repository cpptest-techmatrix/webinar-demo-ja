pipeline {
    agent any

    stages {
        stage('Clone Project from GitHub') {
            steps {
                sh 'echo "Clone Project from GitHub"'
                sh 'git clone https://github.com/cpptest-techmatrix/webinar-demo-ja'
            }
        }
        stage('Create Docker Image') {
            steps {
                sh 'echo "Create Docker Image"'
//                sh '''cp /home/ubuntu/webinar-demo/dockerfile/Dockerfile ./
//                cp /home/ubuntu/dockerfile/bxarm-8.50.9.deb ./
//                docker build -t cpptest:cpptest .'''
            }
        }
        stage('Run Docker Container') {
            steps {
                sh 'echo "Run Docker Container"'
//                sh 'docker run --net host --name cpptest_docker --workdir /home/ubuntu -itd -v /home/ubuntu/parasoft:/home/ubuntu/parasoft cpptest:cpptest'
            }
        }
        stage('Clone Project from GitHub') {
            steps {
                sh 'echo "Clone Project from GitHub"'
//                sh 'docker exec --user 1000 -i cpptest_docker git clone https://github.com/kafujisawa/webinar-demo-bxarm-ja'
            }
        }
        stage('Build Project') {
            steps {
                sh 'echo "Build Project"'
//                sh 'docker exec --user 1000 -i webinar-demo-ja /bin/bash -c "cd webinar-demo-ja && cmake . && cpptesttrace --cpptesttraceProjectName=FlowAnalysis make"'
            }
        }
        stage('Create C++test Project') {
            steps {
                sh 'echo "Create C++test Project"'
//                sh 'docker exec --user 1000 -i cpptest_docker cpptestcli -data workspace -bdf webinar-demo-bxarm-ja/compile_commands.json -localsettings webinar-demo-bxarm-ja/cpptest.ls.properties -showdetails'
            }
        }
        stage('Run Tests') {
            parallel {
                stage('Run MISRA Guideline Test') {
                    steps {
                        sh 'echo "Run MISRA Guideline Test"'
//                        sh 'docker exec --user 1000 -i cpptest_docker cpptestcli -data workspace -resource webinar-demo-bxarm-ja -config webinar-demo-bxarm-ja/cpptest.pipeline.MISRA\\ C2012.properties -exclude webinar-demo-bxarm-ja/cpptest.excludes.lst -localsettings webinar-demo-bxarm-ja/cpptest.ls.properties -publish -showdetails -appconsole stdout'
                    }
                }
                stage('Run Security Test') {
                    steps {
                        sh 'echo "Run Security Test"'
                    }
                }
                stage('Run Unit Tests') {
                    steps {
                        sh 'echo "Run Unit Tests"'
                    }
                }
            }
        }
        stage('Delete Docker Container') {
            steps {
                sh 'echo "Delete Docker Container"'
//                sh '''docker stop cpptest_docker
//                docker rm cpptest_docker'''
            }
        }
        stage('Delete Docker Image') {
            steps {
                sh 'echo "Delete Docker Container"'
//                sh 'docker rmi cpptest:cpptest'
            }
        }
    }
}

