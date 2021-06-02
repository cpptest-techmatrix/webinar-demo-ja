pipeline {
    agent any

    stages {
        // stage('Clone Project from GitHub') {
        //     steps {
        //         sh 'git clone https://github.com/cpptest-techmatrix/webinar-demo-ja'
        //     }
        // }
        stage('Create Docker Image') {
            steps {
                sh '''cp /home/ubuntu/module/parasoft_cpptest_2020.2.0_linux_x86_64.tar.gz ./
                cp /home/ubuntu/module/license.properties ./
                docker build -t webinar-demo-ja:webinar-demo-ja .'''
            }
        }
        stage('Run Docker Container') {
            steps {
                sh 'docker run --net host --name cpptest-workflow-demo --workdir /home/ubuntu -itd webinar-demo-ja:webinar-demo-ja'
            }
        }
        stage('Build Project') {
            steps {
                sh 'docker exec --user 1000 -i cpptest-workflow-demo /bin/bash -c "cmake . && cpptesttrace --cpptesttraceProjectName=FlowAnalysis make"'
            }
        }
        stage('Create C++test Project') {
            steps {
                sh 'docker exec --user 1000 -i cpptest-workflow-demo cpptestcli -data . -bdf webinar-demo-ja/cpptestscan.bdf -localsettings cpptest.ls.properties -showdetails'
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
                sh '''docker stop cpptest-workflow-demo
                docker rm cpptest-workflow-demo'''
            }
        }
        stage('Delete Docker Image') {
            steps {
                sh 'docker rmi webinar-demo-ja:webinar-demo-ja'
            }
        }
    }
    post {
        success {
            cleanWs()
        }
    }
}

