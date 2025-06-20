// Copyright 2024 TIER IV, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef AUTOWARE__POINTCLOUD_PREPROCESSOR__OUTLIER_FILTER__VOXEL_GRID_OUTLIER_FILTER_NODE_HPP_
#define AUTOWARE__POINTCLOUD_PREPROCESSOR__OUTLIER_FILTER__VOXEL_GRID_OUTLIER_FILTER_NODE_HPP_

#include "autoware/pointcloud_preprocessor/filter.hpp"

#include <pcl/filters/voxel_grid.h>
#include <pcl/search/pcl_search.h>

#include <vector>

namespace autoware::pointcloud_preprocessor
{
class VoxelGridOutlierFilterComponent : public autoware::pointcloud_preprocessor::Filter
{
protected:
  virtual void filter(
    const PointCloud2ConstPtr & input, const IndicesPtr & indices, PointCloud2 & output);

  /** \brief Parameter service callback result : needed to be hold */
  OnSetParametersCallbackHandle::SharedPtr set_param_res_;

  /** \brief Parameter service callback */
  rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> & p);

private:
  double voxel_size_x_;
  double voxel_size_y_;
  double voxel_size_z_;
  int voxel_points_threshold_;

  pcl::VoxelGrid<pcl::PointXYZ> voxel_filter;

public:
  PCL_MAKE_ALIGNED_OPERATOR_NEW
  explicit VoxelGridOutlierFilterComponent(const rclcpp::NodeOptions & option);
};
}  // namespace autoware::pointcloud_preprocessor

#endif  // AUTOWARE__POINTCLOUD_PREPROCESSOR__OUTLIER_FILTER__VOXEL_GRID_OUTLIER_FILTER_NODE_HPP_
