add_subdirectory(algorithm)
add_subdirectory(graphics)

set(itests_target
    triangleitestexe
    trianglecoloritestexe
    rectangleitestexe
    cubeitestexe
    windowitestexe
    texturebasicitestexe
    multipletexturesitestexe
    textureandcoloritestexe
    transformtranslateitestexe
    transformrotateitestexe
    transformscaleitestexe
    updatefunctionitestexe
    camerastaticitestexe
    cameramovementitestexe
    groundcubemodelitestexe)

add_custom_target(itests DEPENDS ${itests_target})
