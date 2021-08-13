pipeline {
    agent any
    environment
    {
        // for Docker
        DOCKER_IMAGE_NAME='webinar-demo-ja'
        DOCKER_IMAGE_TAG='webinar-demo-ja'
        DOCKER_CONTAINER_NAME='cpptest-workflow'
        HOST_HOME_DIR='/home/ubuntu'
        CONTAINER_HOME_DIR='/home/ubuntu/webinar-demo-ja'
        // for cpptest
        CPPTEST_PROJECT_NAME='FlowAnalysis'
        CPPTEST_CONFIG_MISRA='user://MISRA C 2012'
        CPPTEST_CONFIG_CERT='builtin://SEI CERT C Rules'
        CPPTEST_CONFIG_UNIT_TEST='user://03. Run Unit Tests for ARM'
    }
    stages {
        stage('Create Docker Image') {
            steps {
                sh '''cp ${HOST_HOME_DIR}/module/parasoft_cpptest_2020.2.0_linux_x86_64.tar.gz ./
                cp ${HOST_HOME_DIR}/module/license.properties ./
                docker build -t ${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG} .'''
            }
        }
        stage('Run Docker Container') {
            steps {
                sh 'docker run --net host --name ${DOCKER_CONTAINER_NAME} --workdir ${CONTAINER_HOME_DIR} -v ${HOST_HOME_DIR}/cpptest_workflow/webinar-demo-ja:${CONTAINER_HOME_DIR} -itd ${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG}'
            }
        }
        stage('Build Project') {
            steps {
                sh 'docker exec --user 1000 -i ${DOCKER_CONTAINER_NAME} /bin/bash -c "cd ${CPPTEST_PROJECT_NAME} && cmake . && cpptesttrace --cpptesttraceProjectName=${CPPTEST_PROJECT_NAME} make"'
            }
        }
        stage('Create C++test Project') {
            steps {
                sh 'docker exec --user 1000 -i ${DOCKER_CONTAINER_NAME} cpptestcli -data . -bdf ${CPPTEST_PROJECT_NAME}/cpptestscan.bdf -localsettings cpptest.ls.properties -showdetails'
            }
        }
        stage('Run Tests') {
            parallel {
                stage('Run MISRA Guideline Test') {
                    steps {
                        sh 'echo "Run MISRA Guideline Test"'
                        //sh 'docker exec --user 1000 -i ${DOCKER_CONTAINER_NAME} cpptestcli -data . -resource ${CPPTEST_PROJECT_NAME} -config ${CPPTEST_CONFIG_MISRA} -localsettings cpptest.ls.properties -showdetails -appconsole stdout'
                    }
                }
                stage('Run Security Test') {
                    steps {
                        sh 'echo "Run Security Test"'
                        //sh 'docker exec --user 1000 -i ${DOCKER_CONTAINER_NAME} cpptestcli -data . -resource ${CPPTEST_PROJECT_NAME} -config ${CPPTEST_CONFIG_CERT} -localsettings cpptest.ls.properties -showdetails -appconsole stdout'
                    }
                }
                stage('Run Unit Tests') {
                    steps {
                        sh 'echo "Run Unit Tests"'
                        //sh 'docker exec --user 1000 -i ${DOCKER_CONTAINER_NAME} cpptestcli -data . -resource ${CPPTEST_PROJECT_NAME} -config ${CPPTEST_CONFIG_UNIT_TEST} -localsettings cpptest.ls.properties -showdetails -appconsole stdout'
                    }
                }
            }
        }
        stage('Delete Docker Container') {
            steps {
                sh '''docker stop ${DOCKER_CONTAINER_NAME}
                docker rm ${DOCKER_CONTAINER_NAME}'''
            }
        }
        stage('Delete Docker Image') {
            steps {
                sh 'docker rmi ${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG}'
            }
        }
    }
    post {
        success {
            cleanWs()
        }
    }
}

