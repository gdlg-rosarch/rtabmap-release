# Script generated with Bloom
pkgdesc="ROS - RTAB-Map's standalone library. RTAB-Map is a RGB-D SLAM approach with real-time constraints."
url='http://introlab.github.io/rtabmap'

pkgname='ros-kinetic-rtabmap'
pkgver='0.11.13_1'
pkgrel=1
arch=('any')
license=('BSD'
)

makedepends=('cmake'
'libfreenect'
'openni'
'pcl'
'proj'
'ros-kinetic-cv-bridge'
'ros-kinetic-octomap'
'ros-kinetic-qt-gui-cpp'
'sqlite'
'vtk'
'zlib'
)

depends=('libfreenect'
'openni'
'pcl'
'ros-kinetic-cv-bridge'
'ros-kinetic-octomap'
'ros-kinetic-qt-gui-cpp'
'sqlite'
'vtk'
'zlib'
)

conflicts=()
replaces=()

_dir=rtabmap
source=()
md5sums=()

prepare() {
    cp -R $startdir/rtabmap $srcdir/rtabmap
}

build() {
  # Use ROS environment variables
  source /usr/share/ros-build-tools/clear-ros-env.sh
  [ -f /opt/ros/kinetic/setup.bash ] && source /opt/ros/kinetic/setup.bash

  # Create build directory
  [ -d ${srcdir}/build ] || mkdir ${srcdir}/build
  cd ${srcdir}/build

  # Fix Python2/Python3 conflicts
  /usr/share/ros-build-tools/fix-python-scripts.sh -v 2 ${srcdir}/${_dir}

  # Build project
  cmake ${srcdir}/${_dir} \
        -DCMAKE_BUILD_TYPE=Release \
        -DCATKIN_BUILD_BINARY_PACKAGE=ON \
        -DCMAKE_INSTALL_PREFIX=/opt/ros/kinetic \
        -DPYTHON_EXECUTABLE=/usr/bin/python2 \
        -DPYTHON_INCLUDE_DIR=/usr/include/python2.7 \
        -DPYTHON_LIBRARY=/usr/lib/libpython2.7.so \
        -DPYTHON_BASENAME=-python2.7 \
        -DSETUPTOOLS_DEB_LAYOUT=OFF
  make
}

package() {
  cd "${srcdir}/build"
  make DESTDIR="${pkgdir}/" install
}

